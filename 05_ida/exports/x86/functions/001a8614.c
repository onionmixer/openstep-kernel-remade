/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8614. */
int __cdecl -[IODirectDevice attachInterruptPort](IODirectDevice *self, SEL a2)
{
  int v2; // eax
  id v4; // eax
  int v5; // eax
  int interruptPort; // [esp-4h] [ebp-8h]

  if ( self->_interruptPort ) /*0x1a861b*/
    return 0; /*0x1a861b*/
  v2 = task_self(); /*0x1a862b*/
  if ( port_allocate_EXTERNAL(v2) ) /*0x1a8631*/
    return -729; /*0x1a8642*/
  v4 = objc_msgSend(self->_deviceDescriptionDelegate, sel_device); /*0x1a8660*/
  if ( objc_msgSend(v4, sel_attachInterruptPort_) ) /*0x1a8669*/
    return 0; /*0x1a8698*/
  interruptPort = self->_interruptPort; /*0x1a867b*/
  v5 = task_self(); /*0x1a867c*/
  port_deallocate_EXTERNAL(v5, interruptPort); /*0x1a8682*/
  self->_interruptPort = 0; /*0x1a8687*/
  return -729; /*0x1a869a*/
}
