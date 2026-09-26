# Decompiler issue boundary

Control-flow and call targets are taken from raw instructions. Exported names identify addresses
but do not establish helper contracts. A join at the final epilogue is not treated as proof that
all preceding helper effects were rolled back.
