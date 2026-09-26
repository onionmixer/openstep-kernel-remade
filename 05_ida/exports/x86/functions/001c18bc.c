/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c18bc. */
int __cdecl +[IODirectDevice setPCIConfigSpace:withDeviceDescription:](
        id a1,
        SEL a2,
        $753F089B692BDCBCFC42C16D2A86E59C *a3,
        id a4)
{
  id v4; // edi
  int result; // eax
  int v7; // ebx
  int v8; // [esp-4h] [ebp-14h]
  unsigned __int8 v9; // [esp+Dh] [ebp-3h] BYREF
  unsigned __int8 v10; // [esp+Eh] [ebp-2h] BYREF
  unsigned __int8 v11; // [esp+Fh] [ebp-1h] BYREF

  v4 = +[KernBus lookupBusInstanceWithName:busId:](aKernbus, sel_lookupBusInstanceWithName_busId_, "PCI", 0); /*0x1c18e2*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_isPCIPresent) ) /*0x1c18ef*/
    return -704; /*0x1c18fb*/
  result = (int)objc_msgSend(a4, sel_getPCIdevice_function_bus_, &v11, &v10, &v9); /*0x1c191b*/
  if ( !result ) /*0x1c1925*/
  {
    v7 = 0; /*0x1c192a*/
    while ( 1 ) /*0x1c192e*/
    {
      v8 = *(_DWORD *)&a3->var0; /*0x1c192e*/
      a3 = ($753F089B692BDCBCFC42C16D2A86E59C *)((char *)a3 + 4); /*0x1c192f*/
      result = (int)objc_msgSend(v4, aSetregisterDev, (unsigned __int8)v7, v11, v10, v9, v8); /*0x1c194d*/
      if ( result ) /*0x1c1957*/
        break; /*0x1c1957*/
      v7 += 4; /*0x1c1959*/
      if ( v7 > 255 ) /*0x1c1962*/
        return 0; /*0x1c1964*/
    }
  }
  return result; /*0x1c1969*/
}
