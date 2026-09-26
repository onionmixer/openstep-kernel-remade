// Read-only evidence acquisition in a dedicated script directory. Numeric analysis is in Python.
// @category OPENSTEP
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.mem.*;
import com.google.gson.*;
import java.nio.file.*;
import java.util.*;
import java.io.*;

public class ReviewKernel extends GhidraScript {
 public void run() throws Exception {
  Path out=Path.of(getScriptArgs()[0]);Files.createDirectories(out);
  Gson gson=new Gson();
  List<Map<String,Object>> memory=new ArrayList<>();
  for(MemoryBlock b:currentProgram.getMemory().getBlocks()) {
   Map<String,Object> row=new LinkedHashMap<>();row.put("name",b.getName());row.put("start",b.getStart().toString());row.put("end",b.getEnd().toString());
   row.put("initialized",b.isInitialized());
   if(b.isInitialized()) {
    byte[] bytes=new byte[(int)b.getSize()];b.getBytes(b.getStart(),bytes);
    row.put("base64",Base64.getEncoder().encodeToString(bytes));
   }
   memory.add(row);
  }
  Files.writeString(out.resolve("memory.json"),gson.toJson(memory));
  DecompInterface d=new DecompInterface();DecompileOptions options=new DecompileOptions();options.grabFromProgram(currentProgram);d.setOptions(options);
  if(!d.openProgram(currentProgram))throw new IllegalStateException(d.getLastMessage());
  try(BufferedWriter writer=Files.newBufferedWriter(out.resolve("functions.jsonl"))) {
   for(Function f:currentProgram.getFunctionManager().getFunctions(true)) {
    monitor.checkCancelled();
    Map<String,Object> row=new LinkedHashMap<>();row.put("entry",f.getEntryPoint().toString());row.put("name",f.getName());row.put("noreturn",f.hasNoReturn());
    DecompileResults res=d.decompileFunction(f,60,monitor);row.put("completed",res.decompileCompleted());row.put("message",res.getErrorMessage());
    if(res.getHighFunction()!=null) {
     HighFunction high=res.getHighFunction();List<Map<String,Object>> blocks=new ArrayList<>();Set<String> pcodeAddresses=new TreeSet<>();
     for(PcodeBlockBasic block:high.getBasicBlocks()) {
      Set<String> addresses=new TreeSet<>();Iterator<PcodeOp> ops=block.getIterator();
      while(ops.hasNext()){PcodeOp op=ops.next();addresses.add(op.getSeqnum().getTarget().toString());}
      blocks.add(Map.of("start",block.getStart().toString(),"stop",block.getStop().toString(),"addresses",addresses));pcodeAddresses.addAll(addresses);
     }
     row.put("blocks",blocks);row.put("pcode_addresses",pcodeAddresses);
     List<Map<String,Object>> tables=new ArrayList<>();
     for(JumpTable table:high.getJumpTables())tables.add(Map.of("switch",table.getSwitchAddress().toString(),"cases",Arrays.stream(table.getCases()).map(Object::toString).toList()));
     row.put("jump_tables",tables);
    }
    if(res.getCCodeMarkup()!=null) {
     List<ClangNode> tokens=new ArrayList<>();res.getCCodeMarkup().flatten(tokens);Set<String> addresses=new TreeSet<>();
     for(ClangNode token:tokens)if(token.getMinAddress()!=null)addresses.add(token.getMinAddress().toString());
     row.put("c_token_addresses",addresses);
    }
    writer.write(gson.toJson(row));writer.newLine();writer.flush();d.flushCache();
   }
  } finally { d.dispose(); }
  println("Read-only decompiler review export complete");
 }
}
