// Ghidra API extraction only. Addresses and selection are computed by Python.
// @category OPENSTEP
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import com.google.gson.*;
import java.nio.file.*;
import java.util.*;

public class WaitPcodeEvidence extends GhidraScript {
 private final Gson gson=new GsonBuilder().setPrettyPrinting().create();
 private Map<String,Object> operation(PcodeOp op){
  Map<String,Object> r=new LinkedHashMap<>();
  r.put("address",op.getSeqnum().getTarget().toString());r.put("opcode",op.getMnemonic());
  r.put("sequence",op.getSeqnum().toString());
  r.put("output",op.getOutput()==null?null:op.getOutput().toString());
  List<String> inputs=new ArrayList<>();for(Varnode v:op.getInputs())inputs.add(v.toString());
  r.put("inputs",inputs);return r;
 }
 public void run()throws Exception{
  Path out=Path.of(getScriptArgs()[0]);
  JsonObject job=JsonParser.parseString(Files.readString(Path.of(getScriptArgs()[1]))).getAsJsonObject();
  if(!job.get("binary_sha256").getAsString().equalsIgnoreCase(currentProgram.getExecutableSHA256()))throw new IllegalStateException("Wrong input");
  DecompInterface d=new DecompInterface();DecompileOptions options=new DecompileOptions();options.grabFromProgram(currentProgram);d.setOptions(options);
  if(!d.openProgram(currentProgram))throw new IllegalStateException(d.getLastMessage());
  List<Map<String,Object>> rows=new ArrayList<>();
  try{for(JsonElement value:job.getAsJsonArray("selected")){
   Function f=currentProgram.getFunctionManager().getFunctionAt(currentProgram.getAddressFactory().getAddress(value.getAsString()));
   if(f==null)throw new IllegalStateException("Missing function");
   DecompileResults result=d.decompileFunction(f,60,monitor);
   Map<String,Object> row=new LinkedHashMap<>();row.put("entry",f.getEntryPoint().toString());row.put("name",f.getName());
   row.put("completed",result.decompileCompleted());row.put("message",result.getErrorMessage());
   row.put("signature",f.getSignature().getPrototypeString());
   if(result.getDecompiledFunction()!=null)Files.writeString(out.resolve(f.getEntryPoint()+".c"),result.getDecompiledFunction().getC());
   List<Map<String,Object>> blocks=new ArrayList<>();
   if(result.getHighFunction()!=null)for(PcodeBlockBasic block:result.getHighFunction().getBasicBlocks()){
    Map<String,Object> b=new LinkedHashMap<>();b.put("index",block.getIndex());
    b.put("start",block.getStart().toString());b.put("stop",block.getStop().toString());
    List<Map<String,Object>> ops=new ArrayList<>();Iterator<PcodeOp> it=block.getIterator();
    while(it.hasNext())ops.add(operation(it.next()));b.put("operations",ops);blocks.add(b);
   }
   row.put("high_blocks",blocks);
   List<Map<String,Object>> raw=new ArrayList<>();
   for(Instruction ins:currentProgram.getListing().getInstructions(f.getBody(),true)){
    Map<String,Object> r=new LinkedHashMap<>();r.put("address",ins.getAddress().toString());r.put("text",ins.toString());
    List<Map<String,Object>> ops=new ArrayList<>();for(PcodeOp op:ins.getPcode())ops.add(operation(op));r.put("operations",ops);raw.add(r);
   }
   row.put("raw_instructions",raw);rows.add(row);
  }}finally{d.dispose();}
  Files.writeString(out.resolve("pcode.json"),gson.toJson(rows));
  Files.writeString(out.resolve("execution-marker.json"),gson.toJson(Map.of("class",getClass().getName(),"version","wait-pcode-v1","binary_sha256",currentProgram.getExecutableSHA256())));
  println("Read-only wait P-code extraction complete; no transaction or save requested");
 }
}
