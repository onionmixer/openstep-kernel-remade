/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1a50. */
int __cdecl -[IODirectDevice getPCIConfigData:atRegister:](
        IODirectDevice *self,
        SEL a2,
        unsigned int *a3,
        unsigned __int8 a4)
{
  id v4; // eax

  -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c1a67*/
  v4 = -[Object class](self, sel_class); /*0x1c1a81*/
  return (int)objc_msgSend(v4, sel_getPCIConfigData_atRegister_withDeviceDescription_); /*0x1c1a92*/
}
