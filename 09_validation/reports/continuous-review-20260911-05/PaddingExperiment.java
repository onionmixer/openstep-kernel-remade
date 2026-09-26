// Tool-side metadata operations and extraction. Bounds/counts are supplied by Python.
// @category OPENSTEP
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.*;
import com.google.gson.*;
import java.nio.file.*;
import java.io.*;
import java.util.*;

public class PaddingExperiment extends GhidraScript {
 private final Gson gson=new GsonBuilder().setPrettyPrinting().create();
 private Path out;
 private Address start,end,callAddress;
 private Map<String,Function> names=new LinkedHashMap<>();
 private List<Function> selected=new ArrayList<>();
 private void write(Path p,Object v)throws Exception{Files.writeString(p,gson.toJson(v));}
 private List<Map<String,String>> ranges(AddressSetView body){
  List<Map<String,String>> result=new ArrayList<>();
  for(AddressRange r:body.getAddressRanges())result.add(Map.of("start",r.getMinAddress().toString(),"end",r.getMaxAddress().toString()));
  return result;
 }
 private Map<String,Object> unit(CodeUnit cu)throws Exception{
  Map<String,Object> row=new LinkedHashMap<>();row.put("start",cu.getMinAddress().toString());row.put("end",cu.getMaxAddress().toString());
  row.put("kind",cu instanceof Instruction?"instruction":((Data)cu).isDefined()?"data":"undefined");
  row.put("rendering",cu.toString());row.put("bytes",Base64.getEncoder().encodeToString(cu.getBytes()));
  if(cu instanceof Instruction){Instruction i=(Instruction)cu;row.put("flow_override",i.getFlowOverride().toString());
   row.put("fallthrough_override",i.isFallThroughOverridden());row.put("fallthrough",i.getFallThrough()==null?null:i.getFallThrough().toString());}
  return row;
 }
 private void export(String stage,boolean global)throws Exception{
  Path dir=out.resolve(stage);Files.createDirectories(dir);
  Listing listing=currentProgram.getListing();
  List<Map<String,Object>> region=new ArrayList<>();
  AddressSet regionSet=new AddressSet(start,end);
  for(CodeUnit cu:listing.getCodeUnits(regionSet,true))region.add(unit(cu));
  write(dir.resolve("padding-units.json"),region);
  write(dir.resolve("call-unit.json"),unit(listing.getInstructionAt(callAddress)));
  List<Map<String,Object>> bodies=new ArrayList<>();
  for(Function f:currentProgram.getFunctionManager().getFunctions(true))bodies.add(Map.of("entry",f.getEntryPoint().toString(),"name",f.getName(),"body",ranges(f.getBody())));
  write(dir.resolve("all-function-bodies.json"),bodies);
  if(global){
   try(BufferedWriter w=Files.newBufferedWriter(dir.resolve("all-code-units.tsv"))){
    w.write("start\tend\tkind\tflow\tfallthrough\n");
    for(CodeUnit cu:listing.getCodeUnits(true)){
     String kind=cu instanceof Instruction?"instruction":((Data)cu).isDefined()?"data":"undefined";
     String flow="",fall="";
     if(cu instanceof Instruction){Instruction i=(Instruction)cu;flow=i.getFlowOverride().toString();if(i.getFallThrough()!=null)fall=i.getFallThrough().toString();}
     w.write(cu.getMinAddress()+"\t"+cu.getMaxAddress()+"\t"+kind+"\t"+flow+"\t"+fall+"\n");
    }
   }
   try(BufferedWriter w=Files.newBufferedWriter(dir.resolve("all-references.tsv"))){
    w.write("from\tto\ttype\toperand\n");
    AddressIterator it=currentProgram.getReferenceManager().getReferenceSourceIterator(currentProgram.getMemory(),true);
    while(it.hasNext())for(Reference r:currentProgram.getReferenceManager().getReferencesFrom(it.next()))
     w.write(r.getFromAddress()+"\t"+r.getToAddress()+"\t"+r.getReferenceType()+"\t"+r.getOperandIndex()+"\n");
   }
   List<Map<String,String>> memory=new ArrayList<>();
   for(MemoryBlock b:currentProgram.getMemory().getBlocks())if(b.isInitialized()){
    byte[] data=new byte[(int)b.getSize()];b.getBytes(b.getStart(),data);
    memory.add(Map.of("name",b.getName(),"start",b.getStart().toString(),"bytes",Base64.getEncoder().encodeToString(data)));
   }
   write(dir.resolve("initialized-memory.json"),memory);
  }
  DecompInterface d=new DecompInterface();DecompileOptions options=new DecompileOptions();options.grabFromProgram(currentProgram);d.setOptions(options);
  if(!d.openProgram(currentProgram))throw new IllegalStateException(d.getLastMessage());
  List<Map<String,Object>> results=new ArrayList<>();
  try{for(Function f:selected){
   DecompileResults res=d.decompileFunction(f,60,monitor);Map<String,Object> row=new LinkedHashMap<>();
   row.put("entry",f.getEntryPoint().toString());row.put("name",f.getName());row.put("body",ranges(f.getBody()));
   row.put("noreturn",f.hasNoReturn());row.put("completed",res.decompileCompleted());row.put("message",res.getErrorMessage());
   if(res.getDecompiledFunction()!=null)Files.writeString(dir.resolve(f.getEntryPoint()+".c"),res.getDecompiledFunction().getC());
   Set<String> addresses=new TreeSet<>();
   if(res.getHighFunction()!=null)for(PcodeBlockBasic b:res.getHighFunction().getBasicBlocks()){
    Iterator<PcodeOp> it=b.getIterator();while(it.hasNext())addresses.add(it.next().getSeqnum().getTarget().toString());
   }
   row.put("pcode_addresses",addresses);results.add(row);
  }}finally{d.dispose();}
  write(dir.resolve("functions.json"),results);println("Exported stage: "+stage);
 }
 public void run()throws Exception{
  out=Path.of(getScriptArgs()[0]);Files.createDirectories(out);
  JsonObject job=JsonParser.parseString(Files.readString(Path.of(getScriptArgs()[1]))).getAsJsonObject();
  if(!job.get("binary_sha256").getAsString().equalsIgnoreCase(currentProgram.getExecutableSHA256()))throw new IllegalStateException("Wrong binary");
  start=currentProgram.getAddressFactory().getAddress(job.get("start").getAsString());
  end=currentProgram.getAddressFactory().getAddress(job.get("end").getAsString());
  callAddress=currentProgram.getAddressFactory().getAddress(job.get("call_site").getAsString());
  byte[] bytes=new byte[job.get("length").getAsInt()];currentProgram.getMemory().getBytes(start,bytes);
  for(byte b:bytes)if(b!=0)throw new IllegalStateException("Padding is not zero");
  for(Function f:currentProgram.getFunctionManager().getFunctions(true))names.put(f.getName(),f);
  for(String name:List.of("__objc_msgForward","___objc_error","__objc_error","_objc_msgSendv","_objc_msgSend","__switch_tss")){
   if(names.get(name)==null)throw new IllegalStateException("Missing function "+name);selected.add(names.get(name));
  }
  export("baseline",true);
  int tx=currentProgram.startTransaction("Temporary padding classification experiment");
  try{
   Function f=names.get(job.get("function_name").getAsString());
   AddressSet body=new AddressSet(f.getBody());body.deleteRange(start,end);f.setBody(body);
   currentProgram.getListing().clearCodeUnits(start,end,false);
   currentProgram.getListing().createData(start,new ArrayDataType(ByteDataType.dataType,job.get("length").getAsInt(),ByteDataType.dataType.getLength()));
   export("padding_only",false);
   names.get("___objc_error").setNoReturn(true);names.get("__objc_error").setNoReturn(true);
   export("combined",false);
   currentProgram.getListing().getInstructionAt(callAddress).setFallThrough(null);
   export("explicit_no_fallthrough",true);
  }finally{currentProgram.endTransaction(tx,false);}
  println("Padding experiment finished; no program save requested");
 }
}
