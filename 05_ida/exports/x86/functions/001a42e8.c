/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a42e8. */
void __cdecl -[IODevice setName:](IODevice *self, SEL a2, const char *a3)
{
  signed __int32 v3; // ebx

  v3 = strlen(a3); /*0x1a4304*/
  if ( v3 > 79 ) /*0x1a430a*/
    v3 = 79; /*0x1a430c*/
  strncpy(self->_deviceName, a3, v3); /*0x1a4317*/
  self->_deviceName[v3] = 0; /*0x1a431c*/
}
