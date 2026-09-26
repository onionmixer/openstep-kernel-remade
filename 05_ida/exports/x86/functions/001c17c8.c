/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c17c8. */
int __cdecl +[IODirectDevice getPCIConfigSpace:withDeviceDescription:](
        id a1,
        SEL a2,
        $753F089B692BDCBCFC42C16D2A86E59C *a3,
        id a4)
{
  id v4; // edi
  int result; // eax
  int v7; // ebx
  $753F089B692BDCBCFC42C16D2A86E59C *v8; // [esp-4h] [ebp-14h]
  unsigned __int8 v9; // [esp+Dh] [ebp-3h] BYREF
  unsigned __int8 v10; // [esp+Eh] [ebp-2h] BYREF
  unsigned __int8 v11; // [esp+Fh] [ebp-1h] BYREF

  v4 = +[KernBus lookupBusInstanceWithName:busId:](aKernbus, sel_lookupBusInstanceWithName_busId_, "PCI", 0); /*0x1c17ee*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_isPCIPresent) ) /*0x1c17fb*/
    return -704; /*0x1c1807*/
  result = (int)objc_msgSend(a4, sel_getPCIdevice_function_bus_, &v11, &v10, &v9); /*0x1c1827*/
  if ( !result ) /*0x1c1831*/
  {
    v7 = 0; /*0x1c1836*/
    while ( 1 ) /*0x1c1838*/
    {
      v8 = a3; /*0x1c1838*/
      a3 = ($753F089B692BDCBCFC42C16D2A86E59C *)((char *)a3 + 4); /*0x1c1839*/
      result = (int)objc_msgSend(v4, aGetregisterDev, (unsigned __int8)v7, v11, v10, v9, v8); /*0x1c1857*/
      if ( result ) /*0x1c1861*/
        break; /*0x1c1861*/
      v7 += 4; /*0x1c1863*/
      if ( v7 > 255 ) /*0x1c186c*/
        return 0; /*0x1c186e*/
    }
  }
  return result; /*0x1c1873*/
}
