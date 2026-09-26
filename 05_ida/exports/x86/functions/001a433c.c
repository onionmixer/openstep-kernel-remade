/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a433c. */
void __cdecl -[IODevice setDeviceKind:](IODevice *self, SEL a2, const char *a3)
{
  signed __int32 v3; // ebx

  v3 = strlen(a3); /*0x1a4358*/
  if ( v3 > 79 ) /*0x1a435e*/
    v3 = 79; /*0x1a4360*/
  strncpy(self->_deviceKind, a3, v3); /*0x1a436e*/
  self->_deviceKind[v3] = 0; /*0x1a4373*/
}
