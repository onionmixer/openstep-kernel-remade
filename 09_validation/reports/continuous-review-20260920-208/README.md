# Callback-table add and reset wrappers use a matched receiver protocol

The unique direct wrapper for the table setter calls `0x001a9c6c` at
`0x001a453e`. If its return EAX is nonnegative, the wrapper pushes that same
EAX, loads selector-pointer `0x001f9cd8`, pushes the receiver originally held
in ESI, and makes an Objective-C dispatch call. The return index is therefore
the first explicit argument in the shown success-side receiver message.

The unique direct wrapper for the reset reads a value through an Objective-C
dispatch with selector-pointer `0x001f9cd0`, rejects only `-1`, and forwards
the returned EAX to the reset at `0x001a46b9`. It then pushes `-1`, uses the
same selector-pointer `0x001f9cd8` as the add wrapper, pushes its receiver,
and dispatches again. Thus the two static wrappers form an add-success value
forward and reset-sentinel protocol around the same selector address.

This narrows callback-table mutation lifetime: a visible reset follows a
non-sentinel receiver lookup and restores the table cell, while the setter’s
successful returned index is visibly handed to the receiver protocol. It does
not prove that the two wrappers are invoked for the same receiver, that a
stored value is unchanged, the target callback's ABI, or runtime ordering and
lifetime. Open Item 1 remains **in progress**.
