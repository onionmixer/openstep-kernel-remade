// Export every function and every code unit; preserve failures and uncovered ranges.
// @category OPENSTEP
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.framework.Application;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.*;
import com.google.gson.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.io.*;
import java.util.*;

public class ExportKernel extends GhidraScript {
    private final Gson gson = new GsonBuilder().setPrettyPrinting().create();
    private Path out;
    private String sha;

    private void json(Path path, Object object) throws IOException {
        Files.writeString(path, gson.toJson(object) + "\n", StandardCharsets.UTF_8);
    }
    private String address(Address a) { return "0x" + a.toString(); }
    private List<Map<String,Object>> ranges(AddressSetView set) {
        List<Map<String,Object>> result = new ArrayList<>();
        for (AddressRange r : set.getAddressRanges()) {
            result.add(Map.of("start", address(r.getMinAddress()), "end_inclusive",
                address(r.getMaxAddress()), "bytes", r.getLength()));
        }
        return result;
    }
    private String line(CodeUnit unit) {
        return address(unit.getMinAddress()) + "\t" + unit.getLength() + "\t" +
            unit.toString().replace('\n',' ') + "\n";
    }
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) throw new IllegalArgumentException("Expected output directory");
        out = Path.of(args[0]);
        Files.createDirectories(out.resolve("functions"));
        sha = currentProgram.getExecutableSHA256();
        if (!"33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890".equalsIgnoreCase(sha))
            throw new IllegalStateException("Wrong input SHA-256: " + sha);
        Map<String,Object> manifest = new LinkedHashMap<>();
        manifest.put("binary_sha256", sha);
        manifest.put("ghidra_version", Application.getApplicationVersion());
        manifest.put("language", currentProgram.getLanguageID().toString());
        manifest.put("compiler_spec", currentProgram.getCompilerSpec().getCompilerSpecID().toString());
        manifest.put("image_base", address(currentProgram.getImageBase()));
        manifest.put("analysis_options", currentProgram.getOptions(Program.ANALYSIS_PROPERTIES).getOptionNames());
        Map<String,String> optionValues = new TreeMap<>();
        for(String name:currentProgram.getOptions(Program.ANALYSIS_PROPERTIES).getOptionNames())
            optionValues.put(name,currentProgram.getOptions(Program.ANALYSIS_PROPERTIES).getValueAsString(name));
        manifest.put("analysis_option_values",optionValues);
        manifest.put("status", "running");
        json(out.resolve("manifest.json"), manifest);
        Listing listing = currentProgram.getListing();
        AddressSet instructions = new AddressSet();
        AddressSet functionBodies = new AddressSet();
        AddressSet undefined = new AddressSet();
        AddressSet definedData = new AddressSet();
        List<Map<String,Object>> blocks = new ArrayList<>();
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            Map<String,Object> info = new LinkedHashMap<>();
            info.put("name",b.getName()); info.put("start",address(b.getStart()));
            info.put("end_inclusive",address(b.getEnd())); info.put("size",b.getSize());
            info.put("initialized",b.isInitialized()); info.put("execute",b.isExecute());
            info.put("read",b.isRead()); info.put("write",b.isWrite()); blocks.add(info);
        }
        json(out.resolve("memory-blocks.json"),blocks);
        long codeUnits = 0;
        try (BufferedWriter asm = Files.newBufferedWriter(out.resolve("whole-program.asm"));
             BufferedWriter units = Files.newBufferedWriter(out.resolve("code-units.tsv"))) {
            units.write("start\tend_inclusive\tlength\tkind\n");
            for (CodeUnit cu : listing.getCodeUnits(true)) {
                monitor.checkCancelled();
                String kind;
                if (cu instanceof Instruction) { instructions.add(cu.getMinAddress(),cu.getMaxAddress()); kind="instruction"; }
                else if (cu instanceof Data && ((Data)cu).isDefined()) { definedData.add(cu.getMinAddress(),cu.getMaxAddress()); kind="data"; }
                else { undefined.add(cu.getMinAddress(),cu.getMaxAddress()); kind="undefined"; }
                asm.write(line(cu));
                units.write(address(cu.getMinAddress())+"\t"+address(cu.getMaxAddress())+"\t"+cu.getLength()+"\t"+kind+"\n");
                codeUnits++;
            }
        }
        println("Whole-program listing exported: " + codeUnits + " code units");
        try (BufferedWriter names = Files.newBufferedWriter(out.resolve("symbols.tsv"))) {
            names.write("address\tname\ttype\tsource\n");
            for (Symbol s : currentProgram.getSymbolTable().getAllSymbols(true))
                names.write(address(s.getAddress())+"\t"+s.getName(true).replace('\t',' ')+"\t"+s.getSymbolType()+"\t"+s.getSource()+"\n");
        }
        try (BufferedWriter refs = Files.newBufferedWriter(out.resolve("references.tsv"))) {
            refs.write("from\tto\ttype\toperand\n");
            AddressIterator it = currentProgram.getReferenceManager().getReferenceSourceIterator(currentProgram.getMemory(),true);
            while(it.hasNext()) for(Reference r : currentProgram.getReferenceManager().getReferencesFrom(it.next()))
                refs.write(address(r.getFromAddress())+"\t"+address(r.getToAddress())+"\t"+r.getReferenceType()+"\t"+r.getOperandIndex()+"\n");
        }
        DecompInterface decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        options.grabFromProgram(currentProgram);
        decompiler.setOptions(options);
        if (!decompiler.openProgram(currentProgram)) throw new IllegalStateException(decompiler.getLastMessage());
        int total = currentProgram.getFunctionManager().getFunctionCount();
        int processed=0, successful=0;
        List<Map<String,Object>> index = new ArrayList<>();
        List<Map<String,Object>> failures = new ArrayList<>();
        try {
            for(Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                monitor.checkCancelled();
                String stem = f.getEntryPoint().toString();
                Map<String,Object> record = new LinkedHashMap<>();
                record.put("address",address(f.getEntryPoint())); record.put("name",f.getName(true));
                record.put("analysis_fragment",f.getName().startsWith("__analysis_fragment_"));
                record.put("body",ranges(f.getBody())); record.put("body_bytes",f.getBody().getNumAddresses());
                record.put("signature",f.getSignature().toString()); record.put("thunk",f.isThunk());
                record.put("binary_sha256",sha);
                functionBodies.add(f.getBody());
                try(BufferedWriter asm = Files.newBufferedWriter(out.resolve("functions/"+stem+".asm"))) {
                    for(CodeUnit cu : listing.getCodeUnits(f.getBody(),true)) asm.write(line(cu));
                }
                try {
                    DecompileResults result = decompiler.decompileFunction(f,60,monitor);
                    if(result.decompileCompleted() && result.getDecompiledFunction()!=null) {
                        String text = "/* Ghidra decompiler output, not reconstructed GCC 2.7 source.\n"+
                            " * Binary SHA-256: "+sha+"; entry: "+address(f.getEntryPoint())+" */\n"+
                            result.getDecompiledFunction().getC();
                        Files.writeString(out.resolve("functions/"+stem+".c"),text,StandardCharsets.UTF_8);
                        record.put("status","decompiled"); record.put("message",result.getErrorMessage()); successful++;
                    } else {
                        record.put("status","failed"); record.put("message",result.getErrorMessage()); failures.add(record);
                    }
                } catch(Exception error) {
                    record.put("status","failed"); record.put("message",error.toString()); failures.add(record);
                }
                json(out.resolve("functions/"+stem+".json"),record);
                index.add(record); processed++;
                decompiler.flushCache();
                if(processed%100==0) {
                    println("DECOMPILE "+processed+"/"+total+" success="+successful+" failed="+failures.size());
                    json(out.resolve("progress.json"),Map.of("processed",processed,"total",total,"successful",successful,"failed",failures.size()));
                }
            }
        } finally { decompiler.dispose(); }
        json(out.resolve("functions.json"),index);
        json(out.resolve("failures.json"),failures);
        List<Map<String,Object>> types = new ArrayList<>();
        Iterator<DataType> dtIterator=currentProgram.getDataTypeManager().getAllDataTypes();
        while(dtIterator.hasNext()) {
            DataType dt=dtIterator.next(); Map<String,Object> row=new LinkedHashMap<>();
            row.put("path",dt.getPathName());row.put("length",dt.getLength());row.put("definition",dt.toString());
            if(dt instanceof Composite) {
                List<Map<String,Object>> members=new ArrayList<>();
                for(DataTypeComponent component:((Composite)dt).getComponents()) members.add(Map.of(
                    "name",component.getFieldName()==null?"":component.getFieldName(),
                    "offset",component.getOffset(),"length",component.getLength(),"type",component.getDataType().getPathName()));
                row.put("members",members);
            }
            types.add(row);
        }
        json(out.resolve("data-types.json"),types);
        AddressSet orphan = instructions.subtract(functionBodies);
        json(out.resolve("coverage.json"),Map.of("instruction_bytes",instructions.getNumAddresses(),
            "function_body_bytes",functionBodies.getNumAddresses(), "orphan_instruction_ranges",ranges(orphan),
            "undefined_ranges",ranges(undefined),"defined_data_ranges",ranges(definedData)));
        manifest.put("status","export_finished"); manifest.put("functions",processed);
        manifest.put("decompiled",successful); manifest.put("failed",failures.size());
        manifest.put("code_units",codeUnits); manifest.put("coverage_audit_complete",false);
        json(out.resolve("manifest.json"),manifest);
        println("EXPORT FINISHED: functions="+processed+" decompiled="+successful+" failed="+failures.size());
    }
}
