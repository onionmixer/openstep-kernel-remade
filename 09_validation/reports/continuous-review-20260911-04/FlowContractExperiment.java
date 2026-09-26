// Extract tool evidence only. All derived numeric analysis is performed in Python.
// @category OPENSTEP
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.*;
import ghidra.framework.Application;
import com.google.gson.*;
import java.nio.file.*;
import java.util.*;

public class FlowContractExperiment extends GhidraScript {
 private final Gson gson=new GsonBuilder().setPrettyPrinting().create();
 private Path out;
 private Map<String,Function> byName=new LinkedHashMap<>();
 private Set<Function> selected=new LinkedHashSet<>();
 private final List<String> changes=List.of("_jump_label","___objc_error","__objc_error",
     "__return_with_state","_thread_exception_return","_thread_syscall_return");

 private Function named(String name) {
  Function f=byName.get(name);
  if(f==null)throw new IllegalArgumentException("Missing exact function name: "+name);
  return f;
 }

 private void exportStage(String stage) throws Exception {
  Path dir=out.resolve(stage);Files.createDirectories(dir);
  DecompInterface d=new DecompInterface();DecompileOptions options=new DecompileOptions();
  options.grabFromProgram(currentProgram);d.setOptions(options);
  if(!d.openProgram(currentProgram))throw new IllegalStateException(d.getLastMessage());
  List<Map<String,Object>> rows=new ArrayList<>();
  try {
   for(Function f:selected) {
    monitor.checkCancelled();
    Map<String,Object> row=new LinkedHashMap<>();
    row.put("entry",f.getEntryPoint().toString());row.put("name",f.getName());
    row.put("noreturn",f.hasNoReturn());row.put("signature",f.getSignature().toString());
    List<Map<String,String>> body=new ArrayList<>();
    for(AddressRange r:f.getBody().getAddressRanges())body.add(Map.of("start",r.getMinAddress().toString(),"end",r.getMaxAddress().toString()));
    row.put("body",body);
    List<Map<String,String>> listing=new ArrayList<>();
    for(Instruction i:currentProgram.getListing().getInstructions(f.getBody(),true)) {
     Map<String,String> ins=new LinkedHashMap<>();ins.put("address",i.getAddress().toString());
     ins.put("bytes_base64",Base64.getEncoder().encodeToString(i.getBytes()));ins.put("assembly",i.toString());
     ins.put("flow_type",i.getFlowType().toString());ins.put("flow_override",i.getFlowOverride().toString());
     if(i.getFallThrough()!=null)ins.put("fallthrough",i.getFallThrough().toString());listing.add(ins);
    }
    row.put("listing",listing);
    DecompileResults res=d.decompileFunction(f,60,monitor);
    row.put("completed",res.decompileCompleted());row.put("message",res.getErrorMessage());
    if(res.getDecompiledFunction()!=null)Files.writeString(dir.resolve(f.getEntryPoint().toString()+".c"),res.getDecompiledFunction().getC());
    if(res.getHighFunction()!=null) {
     Set<String> addresses=new TreeSet<>();
     for(PcodeBlockBasic b:res.getHighFunction().getBasicBlocks()) {
      Iterator<PcodeOp> ops=b.getIterator();
      while(ops.hasNext())addresses.add(ops.next().getSeqnum().getTarget().toString());
     }
     row.put("pcode_addresses",addresses);
    }
    rows.add(row);
   }
  } finally {d.dispose();}
  Files.writeString(dir.resolve("functions.json"),gson.toJson(rows));println("Exported stage: "+stage);
 }

 public void run() throws Exception {
  out=Path.of(getScriptArgs()[0]);Files.createDirectories(out);
  if(!"33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890".equalsIgnoreCase(currentProgram.getExecutableSHA256()))
   throw new IllegalStateException("Wrong input binary");
  for(Function f:currentProgram.getFunctionManager().getFunctions(true))byName.put(f.getName(),f);
  List<Map<String,String>> calls=new ArrayList<>();
  for(String name:changes) {
   Function target=named(name);selected.add(target);
   for(Reference r:currentProgram.getReferenceManager().getReferencesTo(target.getEntryPoint())) {
    if(!r.getReferenceType().isCall())continue;
    Function owner=currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
    if(owner!=null){selected.add(owner);calls.add(Map.of("from",r.getFromAddress().toString(),"to",target.getEntryPoint().toString(),"owner",owner.getName()));}
   }
  }
  for(String name:List.of("_NXDefaultExceptionRaiser","__objc_msgForward","_NXAllocErrorData",
      "_machdep_call","_kernel_trap","_sleep","__switch_tss","__call_with_stack","_objc_msgSend"))selected.add(named(name));
  Files.writeString(out.resolve("call-sites.json"),gson.toJson(calls));
  Files.writeString(out.resolve("environment.json"),gson.toJson(Map.of("ghidra",Application.getApplicationVersion(),
      "binary_sha256",currentProgram.getExecutableSHA256(),"language",currentProgram.getLanguageID().toString(),
      "compiler_spec",currentProgram.getCompilerSpec().getCompilerSpecID().toString(),"changed_function_names",changes)));
  exportStage("baseline");
  Map<String,Boolean> original=new LinkedHashMap<>();for(String name:changes)original.put(name,named(name).hasNoReturn());
  int transaction=currentProgram.startTransaction("Temporary noreturn hypothesis; discarded");
  try {
   for(String name:changes)named(name).setNoReturn(true);
   exportStage("noreturn");
   for(String name:changes)named(name).setNoReturn(original.get(name));
   exportStage("restored");
  } finally {currentProgram.endTransaction(transaction,false);}
  println("Temporary contract experiment finished; no program save requested");
 }
}
