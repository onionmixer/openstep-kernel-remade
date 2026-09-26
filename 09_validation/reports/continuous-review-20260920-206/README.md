# Open Item 1 remains in progress after additional static analyses

Reports 203–205 and 207–215 add bounded results: a constructor-path producer for
the `_smmap` selector byte, map-record-derived increment/decrement paths and
a full selected bulk-copy inventory for a pointer target’s `+0x30`, and
absence of a direct-relative branch to the page template copy entry, and a
matched callback registration/reset wrapper protocol. Report 209 additionally
separates selected map-entry `WORD +0x28` copy destinations from the `EBX`
entries that later receive an increment, decrement, or comparison, and records
one explicit post-copy zero reset. These
improve static provenance and prevent narrower inventories from being mistaken
for universal writer or caller closure.

Report 210 also corrects the pmap evidence boundary: the earlier
`_pmap_kgetport` table closure resolves to a separate direct-call closure and
is no longer counted as VM pmap initializer evidence. The pmap requirement is
therefore evaluated only against the VM-pmap-scoped bootstrap reports and this
scope correction.

Report 211 adds a direct-literal writer inventory for five selected VM-pmap
bootstrap addresses. It isolates three single direct absolute writers and the
two buffer-base materializations, while retaining computed aliases and runtime
state as open requirements.

Report 216 follows the correctly scoped VM-pmap bootstrap through its common
indirect-table helper. It byte-verifies the `0x001f63f0` assignment, the three
bootstrap field offsets, and the helper's upper-index/entry writer loop. This
adds a concrete static initializer path, but not a complete alias closure or
runtime table state.

Report 212 corrects the page-template reachability boundary: two exported
bodies copy the 48-byte template, and one has five direct relative callers.
The former direct-caller audit of the `_vm_page_init` entry therefore cannot
be interpreted as a template-copy caller closure.

Report 213 verifies that the authorized original-input tree has no boot medium,
bootloader, trace, or runtime memory snapshot. The required runtime values and
lifetime observations therefore remain unavailable without an additional
original execution configuration.

Report 214 records a kernel-only QEMU probe. It provided no linked-kernel
startup or VM memory observation, reinforcing that an unconfigured emulator
does not replace the missing original boot configuration.

Report 215 adds a file-backed callback reset source: its callback field is one
of `_smmap`'s explicit filtered values, so this selected reset path branches
away before the shown callback call.

Report 217 adds two `_vm_map_fork` allocation-result initializer paths: both
store zero at `+0x28` and one at `+0x30` through the same immediate result
register. Its distinct copy path then clears only the copied destination's
low word at `+0x28`. These remain local data-flow facts rather than a complete
writer or lifetime closure.

Report 218 rescans all 5,253 export records for the three page-global address
literals. Every match is an absolute memory operand and none is an immediate
literal used to form an indirect pointer. This narrows one computed-address
class but leaves computed expressions, aliases, non-export code, and runtime
behavior open.

They do not supply execution observation, runtime memory snapshots, a complete
computed-address/alias set, or a proven ownership and destruction boundary.
Each of Open Item 1’s six explicit requirement groups still has at least one
such missing requirement. It must therefore remain **in progress**; this audit
does not authorize completion.
