// Recover binary-proven entries and document the context of undecoded code ranges.
// @category OPENSTEP
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import com.google.gson.*;
import java.nio.file.*;
import java.util.*;

public class RepairAndAudit extends GhidraScript {
    Gson gson=new GsonBuilder().setPrettyPrinting().create();
    Address a(String value){ return toAddr(value); }
    void save(Path p,Object value)throws Exception {Files.writeString(p,gson.toJson(value)+"\n");}
    @Override public void run() throws Exception {
        Path root=Path.of(getScriptArgs()[0]);
        Path out=root.resolve("04_ghidra/exports/x86/repair-pass2"); Files.createDirectories(out);
        JsonObject objc=JsonParser.parseString(Files.readString(root.resolve("03_original/x86/inventory/objc.json"))).getAsJsonObject();
        List<Map<String,Object>> changes=new ArrayList<>();
        Map<String,String> entries=new LinkedHashMap<>();
        for(JsonElement element:objc.getAsJsonArray("missing_ghidra_method_entries")) {
            JsonObject method=element.getAsJsonObject();
            entries.put(method.get("imp").getAsString(),method.get("owner").getAsString()+" "+method.get("selector").getAsString());
        }
        SymbolIterator forward=currentProgram.getSymbolTable().getSymbols("__objc_msgForward");
        while(forward.hasNext())entries.put(forward.next().getAddress().toString(),"original symbol __objc_msgForward");
        for(Map.Entry<String,String> entry:entries.entrySet()) {
            Address address=a(entry.getKey());
            Function prior=getFunctionContaining(address);
            boolean decoded=disassemble(address);
            Function f=getFunctionAt(address);
            if(f==null && prior==null) f=createFunction(address,null);
            setPlateComment(address,"Entry confirmed from original binary metadata: "+entry.getValue());
            changes.add(Map.of("address",address.toString(),"evidence",entry.getValue(),
                "disassembled",decoded,"function_created_or_present",f!=null,
                "prior_containing_function",prior==null?"":prior.getEntryPoint().toString()));
        }
        analyzeChanges(currentProgram);
        save(out.resolve("entry-repairs.json"),changes);
        JsonArray gaps=JsonParser.parseString(Files.readString(root.resolve("09_validation/static/full-analysis/undefined-text-gaps.json"))).getAsJsonArray();
        List<Map<String,Object>> contexts=new ArrayList<>();
        for(JsonElement item:gaps) {
            JsonObject gap=item.getAsJsonObject();
            if(!gap.get("category").getAsString().equals("requires_disassembly_review"))continue;
            Address start=a(gap.get("start").getAsString());
            Map<String,Object> row=new LinkedHashMap<>();
            row.put("start",start.toString());row.put("bytes",gap.get("bytes").getAsLong());
            Instruction previous=getInstructionBefore(start);
            if(previous!=null) {
                row.put("previous_address",previous.getAddress().toString());row.put("previous",previous.toString());
                row.put("adjacent_to_previous",previous.getMaxAddress().next().equals(start));
                row.put("previous_flow",previous.getFlowType().toString());
                Function owner=getFunctionContaining(previous.getAddress());
                row.put("previous_owner",owner==null?"":owner.getEntryPoint().toString());
                List<Map<String,Object>> targets=new ArrayList<>();
                for(Address target:previous.getFlows()) {
                    Function f=getFunctionAt(target);
                    targets.add(Map.of("address",target.toString(),"name",f==null?"":f.getName(),"noreturn",f!=null&&f.hasNoReturn()));
                }
                row.put("targets",targets);
            }
            List<String> refs=new ArrayList<>();
            for(Reference ref:getReferencesTo(start))refs.add(ref.getFromAddress()+":"+ref.getReferenceType());
            row.put("incoming",refs);
            contexts.add(row);
        }
        save(out.resolve("gap-contexts.json"),contexts);
        List<Map<String,Object>> types=new ArrayList<>();
        Iterator<DataType> iter=currentProgram.getDataTypeManager().getAllDataTypes();
        while(iter.hasNext()) {
            DataType dt=iter.next();Map<String,Object> row=new LinkedHashMap<>();
            row.put("path",dt.getPathName());row.put("name",dt.getDisplayName());row.put("length",dt.getLength());row.put("definition",dt.toString());
            if(dt instanceof Composite) {
                List<Map<String,Object>> members=new ArrayList<>();
                for(DataTypeComponent c:((Composite)dt).getComponents())members.add(Map.of(
                    "name",c.getFieldName()==null?"":c.getFieldName(),"offset",c.getOffset(),"length",c.getLength(),"type",c.getDataType().getPathName()));
                row.put("members",members);
            }
            types.add(row);
        }
        save(out.resolve("data-types.json"),types);
        println("Confirmed entries="+entries.size()+"; gap contexts="+contexts.size()+"; data types="+types.size());
    }
}
