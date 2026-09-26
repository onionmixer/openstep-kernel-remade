/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a82e8. */
void __cdecl __noreturn sub_1A82E8(id a1)
{
  id v1; // eax
  const char *v2; // eax
  const char *v3; // [esp-8h] [ebp-10h]
  id v4; // [esp-4h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-4h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 ) /*0x1a8300*/
        {
          v1 = objc_msgSend(a1, sel_waitForInterrupt_, &v5); /*0x1a8300*/
          if ( v1 != (id)-737 ) /*0x1a830d*/
            break; /*0x1a830d*/
          objc_msgSend(a1, sel_receiveMsg); /*0x1a8315*/
        }
        if ( !v1 ) /*0x1a831a*/
          break; /*0x1a831a*/
        v4 = v1; /*0x1a831c*/
        v3 = (const char *)objc_msgSend(a1, sel_deviceKind); /*0x1a832d*/
        v2 = (const char *)objc_msgSend(a1, sel_name); /*0x1a8336*/
        IOLog((int)"%s: %s thread: waitForInterrupt: returns %d\n", v2, v3, v4);
      }
      if ( v5 != 2302756 ) /*0x1a8358*/
        break; /*0x1a8358*/
      objc_msgSend(a1, sel_commandRequestOccurred); /*0x1a8386*/
    }
    if ( v5 > 2302756 ) /*0x1a835a*/
    {
      if ( v5 == 2302757 ) /*0x1a836d*/
      {
        objc_msgSend(a1, sel_interruptOccurred); /*0x1a8390*/
      }
      else
      {
        if ( v5 != 2302774 ) /*0x1a8374*/
          goto LABEL_16; /*0x1a8374*/
        IOExitThread(); /*0x1a83a0*/
      }
    }
    else if ( v5 == 2302755 ) /*0x1a8361*/
    {
      objc_msgSend(a1, sel_timeoutOccurred); /*0x1a837e*/
    }
    else
    {
LABEL_16:
      if ( (unsigned int)(v5 - 2302757) > 0xF ) /*0x1a83b8*/
        objc_msgSend(a1, sel_otherOccurred_, v5); /*0x1a83cd*/
      else
        objc_msgSend(a1, sel_interruptOccurredAt_, v5 - 2302757); /*0x1a83c1*/
    }
  }
}
