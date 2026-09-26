/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1b3c. */
int __cdecl -[IODirectDevice setPCIConfigData:atRegister:](
        IODirectDevice *self,
        SEL a2,
        unsigned int a3,
        unsigned __int8 a4)
{
  id v4; // eax

  -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c1b53*/
  v4 = -[Object class](self, sel_class); /*0x1c1b6d*/
  return (int)objc_msgSend(v4, sel_setPCIConfigData_atRegister_withDeviceDescription_); /*0x1c1b7e*/
}
