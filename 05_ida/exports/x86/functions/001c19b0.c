/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c19b0. */
int __cdecl +[IODirectDevice getPCIConfigData:atRegister:withDeviceDescription:](
        id a1,
        SEL a2,
        unsigned int *a3,
        unsigned __int8 a4,
        id a5)
{
  id v5; // esi
  int result; // eax
  unsigned __int8 v7; // [esp+Dh] [ebp-3h] BYREF
  unsigned __int8 v8; // [esp+Eh] [ebp-2h] BYREF
  unsigned __int8 v9; // [esp+Fh] [ebp-1h] BYREF

  v5 = +[KernBus lookupBusInstanceWithName:busId:](aKernbus, sel_lookupBusInstanceWithName_busId_, "PCI", 0); /*0x1c19db*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_isPCIPresent) ) /*0x1c19e8*/
    return -704; /*0x1c19f4*/
  result = (int)objc_msgSend(a5, sel_getPCIdevice_function_bus_, &v9, &v8, &v7); /*0x1c1a13*/
  if ( !result ) /*0x1c1a1d*/
    return (int)objc_msgSend(v5, aGetregisterDev, a4, v9, v8, v7, a3); /*0x1c1a3f*/
  return result; /*0x1c1a47*/
}
