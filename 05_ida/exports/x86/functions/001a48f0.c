/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a48f0. */
int __cdecl -[IODevice getCharValues:forParameter:count:](
        IODevice *self,
        SEL a2,
        char *__dst,
        char *a4,
        unsigned int *a5)
{
  id v5; // eax
  char *deviceName; // eax
  size_t v7; // esi
  char *__src; // [esp+Ch] [ebp-8h]
  unsigned int v10; // [esp+10h] [ebp-4h]

  v10 = *a5; /*0x1a4901*/
  if ( !*a5 ) /*0x1a4901*/
    v10 = 512; /*0x1a4908*/
  if ( !strcmp(a4, "IOClassName") ) /*0x1a491f*/
  {
    v5 = -[Object class](self, sel_class); /*0x1a4932*/
    __src = (char *)objc_msgSend(v5, sel_name); /*0x1a4940*/
  }
  else
  {
    if ( !strcmp(a4, "IODeviceName") ) /*0x1a4958*/
    {
      deviceName = self->_deviceName; /*0x1a495c*/
    }
    else
    {
      if ( strcmp(a4, "IODeviceKind") ) /*0x1a4974*/
        return -711; /*0x1a49c0*/
      deviceName = self->_deviceKind; /*0x1a4978*/
    }
    __src = deviceName; /*0x1a497d*/
  }
  v7 = strlen(__src); /*0x1a4991*/
  if ( v10 <= v7 ) /*0x1a4997*/
    v7 = v10 - 1; /*0x1a499c*/
  *a5 = v7 + 1; /*0x1a49a3*/
  strncpy(__dst, __src, v7); /*0x1a49ae*/
  __dst[v7] = 0; /*0x1a49b6*/
  return 0; /*0x1a49c8*/
}
