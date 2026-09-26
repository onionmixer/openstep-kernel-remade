// Classify the remaining Python-verified code-address tables as data.
// @category OPENSTEP
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import com.google.gson.*;
import java.nio.file.*;

public class MarkPointerArrays extends GhidraScript {
    @Override public void run()throws Exception {
        Path root=Path.of(getScriptArgs()[0]);
        JsonObject actions=JsonParser.parseString(Files.readString(root.resolve("09_validation/static/full-analysis/gap-actions.json"))).getAsJsonObject();
        for(JsonElement element:actions.getAsJsonArray("pointer_arrays")) {
            JsonObject row=element.getAsJsonObject();Address start=toAddr(row.get("start").getAsString());
            Address end=toAddr(row.get("end_inclusive").getAsString());
            clearListing(start,end);
            createData(start,new ArrayDataType(new PointerDataType(DWordDataType.dataType,4),row.getAsJsonArray("words").size(),4));
            setPlateComment(start,"Code-address table verified from original bytes; targets="+row.get("words"));
        }
        println("Remaining code-address arrays typed; original bytes unchanged");
    }
}
