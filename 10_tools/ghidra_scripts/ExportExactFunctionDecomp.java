// Export Ghidra native decompilation only when the requested address is an
// exact Ghidra function start.  It never changes program analysis.
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class ExportExactFunctionDecomp extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) {
            throw new IllegalArgumentException("usage: <output-directory> <address-file>");
        }
        File outputDirectory = new File(args[0]);
        if (!outputDirectory.isDirectory() && !outputDirectory.mkdirs()) {
            throw new IllegalStateException("could not create output directory: " + outputDirectory);
        }
        BufferedWriter program = new BufferedWriter(new FileWriter(new File(outputDirectory, "program.tsv")));
        program.write("program_name\tlanguage_id\tcompiler_spec_id\n");
        program.write(currentProgram.getName() + "\t" + currentProgram.getLanguageID() + "\t" +
                      currentProgram.getCompilerSpec().getCompilerSpecID() + "\n");
        program.close();
        File addressFile = new File(args[1]);
        FunctionManager manager = currentProgram.getFunctionManager();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        BufferedWriter manifest = new BufferedWriter(new FileWriter(new File(outputDirectory, "manifest.tsv")));
        manifest.write("requested_address\texact_function_start\texact_function_body_min\texact_function_body_max\tcontaining_function_start\tstatus\toutput\tmessage\n");
        BufferedReader input = new BufferedReader(new FileReader(addressFile));
        String addressText;
        while ((addressText = input.readLine()) != null) {
            addressText = addressText.trim();
            if (addressText.isEmpty()) {
                continue;
            }
            Address address = toAddr(addressText);
            Function exact = manager.getFunctionAt(address);
            Function containing = manager.getFunctionContaining(address);
            String exactStart = exact == null ? "" : exact.getEntryPoint().toString();
            String bodyMin = exact == null ? "" : exact.getBody().getMinAddress().toString();
            String bodyMax = exact == null ? "" : exact.getBody().getMaxAddress().toString();
            String containingStart = containing == null ? "" : containing.getEntryPoint().toString();
            String status;
            String output = "";
            String message = "";
            if (exact == null) {
                status = "no_exact_ghidra_function";
            }
            else {
                DecompileResults results = decompiler.decompileFunction(exact, 120, monitor);
                if (results.decompileCompleted() && results.getDecompiledFunction() != null) {
                    output = addressText.replace("0x", "").replace("0X", "") + ".c";
                    BufferedWriter c = new BufferedWriter(new FileWriter(new File(outputDirectory, output)));
                    c.write(results.getDecompiledFunction().getC());
                    c.close();
                    status = "success_exact_function";
                }
                else {
                    status = "native_decompile_failed";
                    message = results.getErrorMessage().replace('\t', ' ').replace('\n', ' ');
                }
            }
            manifest.write(addressText + "\t" + exactStart + "\t" + bodyMin + "\t" + bodyMax + "\t" + containingStart + "\t" + status + "\t" + output + "\t" + message + "\n");
            manifest.flush();
            println("[exact-native-decomp] " + addressText + " " + status);
        }
        input.close();
        manifest.close();
        decompiler.dispose();
    }
}
