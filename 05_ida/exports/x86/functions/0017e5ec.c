/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e5ec. */
id __usercall _io_setDriverPowerState@<eax>(int a1@<ebx>, int a2)
{
  id result; // eax
  id v3; // eax
  int v4; // [esp-8h] [ebp-18h]
  id v5; // [esp+Ch] [ebp-4h] BYREF

  while ( 1 ) /*0x17e604*/
  {
    v4 = a1++; /*0x17e604*/
    result = +[IODevice lookupByObjectNumber:instance:](aIodevice_0, sel_lookupByObjectNumber_instance_, v4, &v5); /*0x17e614*/
    if ( result == (id)-704 ) /*0x17e621*/
      break; /*0x17e621*/
    if ( result != (id)-727 ) /*0x17e628*/
    {
      v3 = objc_msgSend(v5, sel_class); /*0x17e641*/
      if ( (unsigned __int8)objc_msgSend(v3, sel_conformsTo_) ) /*0x17e64a*/
        objc_msgSend(v5, sel_perform_with_, sel_setPowerState_, a2); /*0x17e663*/
    }
  }
  return result; /*0x17e673*/
}
