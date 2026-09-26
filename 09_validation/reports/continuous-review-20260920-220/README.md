# `_thread_setrun` direct-caller inventory

Python scanned the original `__text` bytes for every direct relative call to
`0x0016400c`, the exported `_thread_setrun` entry. It found 18 sites across
thread transition, wakeup, dispatch, release/resume, and swap-in paths. All
are recorded with original call bytes and first post-call instruction.

Seventeen sites immediately execute `ADD ESP,8`; one immediately jumps to a
local continuation. These observations do not assign a source signature or
prove that any caller path runs. Indirect calls, run-queue contents, priority
effects, processor selection, and runtime progress remain outside this static
inventory.

