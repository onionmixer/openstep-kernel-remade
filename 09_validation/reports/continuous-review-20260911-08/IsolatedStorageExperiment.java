// API operations only; numeric layout values and addresses are supplied by Python.
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

public class IsolatedStorageExperiment extends GhidraScript {
 private final Gson gson=new GsonBuilder().setPrettyPrinting().create();
 private Path out;
 private JsonObject job;
 private List<Function> selected=new ArrayList<>();
 private void write(Path path,Object value)throws Exception{Files.writeString(path,gson.toJson(value));}
 private Function at(String value){return currentProgram.getFunctionManager().getFunctionAt(currentProgram.getAddressFactory().getAddress(value));}
 private List<Map<String,String>> ranges(AddressSetView body){
  List<Map<String,String>> rows=new ArrayList<>();
  for(AddressRange r:body.getAddressRanges())rows.add(Map.of("start",r.getMinAddress().toString(),"end",r.getMaxAddress().toString()));
  return rows;
 }
 private Map<String,Object> variable(Variable v){
  Map<String,Object> r=new LinkedHashMap<>();r.put("name",v.getName());r.put("type",v.getDataType().getPathName());
  r.put("length",v.getDataType().getLength());r.put("storage",v.getVariableStorage().toString());r.put("source",v.getSource().toString());
  return r;
 }
 private Map<String,Object> function(Function f){
  Map<String,Object> r=new LinkedHashMap<>();r.put("entry",f.getEntryPoint().toString());r.put("name",f.getName());
  r.put("body",ranges(f.getBody()));r.put("signature",f.getSignature().getPrototypeString());
  r.put("signature_source",f.getSignatureSource().toString());r.put("custom_storage",f.hasCustomVariableStorage());
  r.put("convention",f.getCallingConventionName());r.put("noreturn",f.hasNoReturn());r.put("varargs",f.hasVarArgs());
  r.put("return",variable(f.getReturn()));List<Map<String,Object>> p=new ArrayList<>(),l=new ArrayList<>();
  for(Parameter v:f.getParameters())p.add(variable(v));for(Variable v:f.getLocalVariables())l.add(variable(v));
  r.put("parameters",p);r.put("locals",l);return r;
 }
 private void export(String stage)throws Exception{
  Path dir=out.resolve(stage);Files.createDirectories(dir);
  List<Map<String,Object>> all=new ArrayList<>();
  for(Function f:currentProgram.getFunctionManager().getFunctions(true))all.add(function(f));
  write(dir.resolve("all-functions.json"),all);
  List<Map<String,String>> memory=new ArrayList<>();
  for(MemoryBlock b:currentProgram.getMemory().getBlocks())if(b.isInitialized()){
   byte[] bytes=new byte[(int)b.getSize()];b.getBytes(b.getStart(),bytes);
   memory.add(Map.of("name",b.getName(),"start",b.getStart().toString(),"bytes",Base64.getEncoder().encodeToString(bytes)));
  }
  write(dir.resolve("initialized-memory.json"),memory);
  try(BufferedWriter w=Files.newBufferedWriter(dir.resolve("code-units.tsv"))){
   w.write("start\tend\tkind\tflow\tfallthrough\n");
   for(CodeUnit cu:currentProgram.getListing().getCodeUnits(true)){
    String kind=cu instanceof Instruction?"instruction":((Data)cu).isDefined()?"data":"undefined";
    String flow="",fall="";if(cu instanceof Instruction){Instruction i=(Instruction)cu;flow=i.getFlowOverride().toString();if(i.getFallThrough()!=null)fall=i.getFallThrough().toString();}
    w.write(cu.getMinAddress()+"\t"+cu.getMaxAddress()+"\t"+kind+"\t"+flow+"\t"+fall+"\n");
   }
  }
  try(BufferedWriter w=Files.newBufferedWriter(dir.resolve("references.tsv"))){
   w.write("from\tto\ttype\toperand\n");
   AddressIterator it=currentProgram.getReferenceManager().getReferenceSourceIterator(currentProgram.getMemory(),true);
   while(it.hasNext())for(Reference r:currentProgram.getReferenceManager().getReferencesFrom(it.next()))
    w.write(r.getFromAddress()+"\t"+r.getToAddress()+"\t"+r.getReferenceType()+"\t"+r.getOperandIndex()+"\n");
  }
  DecompInterface d=new DecompInterface();DecompileOptions o=new DecompileOptions();o.grabFromProgram(currentProgram);d.setOptions(o);
  if(!d.openProgram(currentProgram))throw new IllegalStateException(d.getLastMessage());
  List<Map<String,Object>> results=new ArrayList<>();
  try{for(Function f:selected){
   DecompileResults res=d.decompileFunction(f,60,monitor);Map<String,Object> r=function(f);
   r.put("completed",res.decompileCompleted());r.put("message",res.getErrorMessage());
   if(res.getDecompiledFunction()!=null)Files.writeString(dir.resolve(f.getEntryPoint()+".c"),res.getDecompiledFunction().getC());
   List<Map<String,Object>> calls=new ArrayList<>();
   if(res.getHighFunction()!=null){Iterator<PcodeOpAST> ops=res.getHighFunction().getPcodeOps();
    while(ops.hasNext()){PcodeOpAST op=ops.next();if(op.getOpcode()!=PcodeOp.CALL&&op.getOpcode()!=PcodeOp.CALLIND)continue;
     List<String> inputs=new ArrayList<>();for(Varnode input:op.getInputs())inputs.add(input.toString());
     calls.add(Map.of("address",op.getSeqnum().getTarget().toString(),"opcode",op.getMnemonic(),"inputs",inputs));
    }
   }
   r.put("pcode_calls",calls);results.add(r);
  }}finally{d.dispose();}
  write(dir.resolve("functions.json"),results);println("Exported stage "+stage);
 }
 private void applyHidden()throws Exception{
  DataTypeManager dtm=currentProgram.getDataTypeManager();
  for(JsonElement element:job.getAsJsonArray("hidden")){
   JsonObject item=element.getAsJsonObject();Function f=at(item.get("entry").getAsString());
   StructureDataType structure=new StructureDataType(new CategoryPath("/review_storage"),item.get("type_name").getAsString(),0,dtm);
   for(JsonElement field:item.getAsJsonArray("fields")){
    JsonObject v=field.getAsJsonObject();DataType scalar=v.get("char").getAsBoolean()?CharDataType.dataType:ByteDataType.dataType;
    structure.add(new ArrayDataType(scalar,v.get("length").getAsInt(),scalar.getLength()),v.get("name").getAsString(),null);
   }
   DataType ptr=new PointerDataType(dtm.resolve(structure,DataTypeConflictHandler.DEFAULT_HANDLER),dtm);
   List<Variable> params=new ArrayList<>();
   params.add(new ParameterImpl("result_buffer",ptr,currentProgram.getRegister("EBX"),currentProgram,SourceType.USER_DEFINED));
   for(JsonElement field:item.getAsJsonArray("stack_parameters")){
    JsonObject v=field.getAsJsonObject();DataType type=new PointerDataType(VoidDataType.dataType,dtm);
    params.add(new ParameterImpl(v.get("name").getAsString(),type,v.get("offset").getAsInt(),currentProgram,SourceType.USER_DEFINED));
   }
   Variable ret=new ReturnParameterImpl(ptr,currentProgram.getRegister("EAX"),currentProgram);
   f.updateFunction(null,ret,params,Function.FunctionUpdateType.CUSTOM_STORAGE,false,SourceType.USER_DEFINED);
  }
 }
 private void applyCompress()throws Exception{
  JsonObject item=job.getAsJsonObject("compress");Function f=at(item.get("entry").getAsString());
  DataType type=IntegerDataType.dataType.clone(currentProgram.getDataTypeManager());
  List<Variable> params=new ArrayList<>();
  for(JsonElement value:item.getAsJsonArray("parameters"))params.add(new ParameterImpl(value.getAsString(),type,currentProgram,SourceType.USER_DEFINED));
  f.updateFunction(null,new ReturnParameterImpl(type,currentProgram),params,Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,false,SourceType.USER_DEFINED);
 }
 public void run()throws Exception{
  out=Path.of(getScriptArgs()[0]);job=JsonParser.parseString(Files.readString(Path.of(getScriptArgs()[1]))).getAsJsonObject();
  if(!job.get("binary_sha256").getAsString().equalsIgnoreCase(currentProgram.getExecutableSHA256()))throw new IllegalStateException("Wrong binary");
  for(JsonElement a:job.getAsJsonArray("selected")){Function f=at(a.getAsString());if(f==null)throw new IllegalStateException("Missing function");selected.add(f);}
  String stage=getScriptArgs()[2];
  write(out.resolve(stage+"-execution-marker.json"),Map.of("class",getClass().getName(),"version","isolated-storage-v2","stage",stage));
  List<Map<String,Object>> initial=new ArrayList<>();
  for(Function f:currentProgram.getFunctionManager().getFunctions(true))initial.add(function(f));
  write(out.resolve(stage+"-input-functions.json"),initial);
  if(!List.of("baseline","hidden_only","compress_only","combined","reopened_baseline").contains(stage))throw new IllegalStateException("Invalid phase");
  int tx=currentProgram.startTransaction("Isolated signature experiment "+stage);
  try{
   if(stage.equals("hidden_only")||stage.equals("combined"))applyHidden();
   if(stage.equals("compress_only")||stage.equals("combined"))applyCompress();
   export(stage);
  }finally{currentProgram.endTransaction(tx,false);}
  println("Isolated storage experiment completed; no save requested");
 }
}
