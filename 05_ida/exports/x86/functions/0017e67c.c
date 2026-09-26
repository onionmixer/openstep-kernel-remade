/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e67c. */
id __usercall _ioSetDriverPowerManagementState@<eax>(int a1@<ebx>, int a2)
{
  id result; // eax
  id v3; // eax
  int v4; // [esp-8h] [ebp-18h]
  id v5; // [esp+Ch] [ebp-4h] BYREF

  while ( 1 ) /*0x17e694*/
  {
    v4 = a1++; /*0x17e694*/
    result = +[IODevice lookupByObjectNumber:instance:](aIodevice_0, sel_lookupByObjectNumber_instance_, v4, &v5); /*0x17e6a4*/
    if ( result == (id)-704 ) /*0x17e6b1*/
      break; /*0x17e6b1*/
    if ( result != (id)-727 ) /*0x17e6b8*/
    {
      v3 = objc_msgSend(v5, sel_class); /*0x17e6d1*/
      if ( (unsigned __int8)objc_msgSend(v3, sel_conformsTo_) ) /*0x17e6da*/
        objc_msgSend(v5, sel_perform_with_, sel_setPowerManagement_, a2); /*0x17e6f3*/
    }
  }
  return result; /*0x17e703*/
}
