// Apply Python-calculated corrections. Synthetic fragments are explicitly not ABI functions.
// @category OPENSTEP
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import com.google.gson.*;
import java.nio.file.*;
import java.util.*;

public class CompleteCode extends GhidraScript {
    @Override public void run()throws Exception {
        Path root=Path.of(getScriptArgs()[0]);
        JsonObject actions=JsonParser.parseString(Files.readString(root.resolve("09_validation/static/full-analysis/gap-actions.json"))).getAsJsonObject();
        List<Map<String,Object>> result=new ArrayList<>();
        for(JsonElement item:actions.getAsJsonArray("data_corrections")) {
            JsonObject r=item.getAsJsonObject();Address start=toAddr(r.get("start").getAsString()),end=toAddr(r.get("end_inclusive").getAsString());
            Function f=getFunctionAt(start);if(f!=null)currentProgram.getFunctionManager().removeFunction(start);
            clearListing(start,end);
            createData(start,new ArrayDataType(DWordDataType.dataType,4,4));
            setPlateComment(start,"Data, not a function: "+r.get("symbol").getAsString()+". "+r.get("evidence").getAsString());
            result.add(Map.of("start",start.toString(),"role","data_correction","removed_false_function",f!=null));
        }
        for(JsonElement item:actions.getAsJsonArray("code_actions")) {
            monitor.checkCancelled();
            JsonObject r=item.getAsJsonObject();Address start=toAddr(r.get("start").getAsString()),end=toAddr(r.get("end_inclusive").getAsString());
            String role=r.get("role").getAsString();
            AddressSet body=new AddressSet();boolean success=true;
            for(JsonElement instruction:r.getAsJsonArray("instructions")) {
                Address at=toAddr(instruction.getAsJsonObject().get("address").getAsString());
                Instruction ins=getInstructionAt(at);
                if(ins==null) {
                    DisassembleCommand cmd=new DisassembleCommand(at,new AddressSet(start,end),false);
                    cmd.applyTo(currentProgram,monitor);ins=getInstructionAt(at);
                }
                if(ins==null){success=false;break;}
                if(!ins.getMnemonicString().equalsIgnoreCase("NOP"))body.add(ins.getMinAddress(),ins.getMaxAddress());
            }
            Map<String,Object> record=new LinkedHashMap<>();record.put("start",start.toString());record.put("end_inclusive",end.toString());record.put("role",role);record.put("decoded",success);
            if(success && role.equals("resumable_instruction_tail")) {
                JsonObject context=r.getAsJsonObject("context");
                Instruction previous=getInstructionAt(toAddr(context.get("previous_address").getAsString()));
                previous.setFallThrough(start);
                Function owner=getFunctionAt(toAddr(context.get("previous_owner").getAsString()));
                boolean fixed=CreateFunctionCmd.fixupFunctionBody(currentProgram,owner,monitor);
                record.put("body_fixed",fixed);record.put("owner",owner.getEntryPoint().toString());
            } else if(success) {
                Function existing=getFunctionContaining(start);
                if(existing==null) {
                    try {
                        Function fragment=currentProgram.getFunctionManager().createFunction("__analysis_fragment_"+start,start,body,SourceType.USER_DEFINED);
                        fragment.setComment("Synthetic analysis entry; not a reconstructed ABI function. Role="+role+". Context recorded in gap-actions.json.");
                        record.put("fragment_created",true);
                    } catch(Exception e){record.put("error",e.toString());}
                } else record.put("existing_owner",existing.getEntryPoint().toString());
            }
            result.add(record);
        }
        Path out=root.resolve("04_ghidra/exports/x86/repair-pass3");Files.createDirectories(out);
        Files.writeString(out.resolve("actions.json"),new GsonBuilder().setPrettyPrinting().create().toJson(result)+"\n");
        println("Bounded code/data corrections exported");
    }
}
