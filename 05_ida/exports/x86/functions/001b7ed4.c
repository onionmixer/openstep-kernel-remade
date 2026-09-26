/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7ed4. */
void __cdecl -[AudioChannel freeDescriptors](AudioChannel *self, SEL a2)
{
  while ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->dmaQueue.next != &self->dmaQueue ) /*0x1b7ee2*/
    -[AudioChannel dequeueDescriptor](self, sel_dequeueDescriptor); /*0x1b7ef0*/
  -[AudioChannel initializeFreeQueue](self, sel_initializeFreeQueue); /*0x1b7f05*/
}
