/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b5d68. */
void __cdecl __noreturn sub_1B5D68(id a1)
{
  id v1; // eax
  int v2; // eax
  id v3; // eax
  const char *v4; // eax
  const char *v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-4h] [ebp-24h]
  _DWORD v7[5]; // [esp+8h] [ebp-18h] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 ) /*0x1b5d78*/
        {
          v7[1] = 24; /*0x1b5d78*/
          v7[3] = objc_msgSend(a1, sel__devicePortSet); /*0x1b5d8c*/
          v1 = objc_msgSend(a1, sel__timeout); /*0x1b5d97*/
          v2 = msg_receive(v7, 256, (int)v1); /*0x1b5da3*/
          if ( v2 != -203 ) /*0x1b5db0*/
            break; /*0x1b5db0*/
          if ( (unsigned __int8)objc_msgSend(a1, sel_isInputActive) /*0x1b5e4c*/
            || (unsigned __int8)objc_msgSend(a1, sel_isOutputActive) )
          {
            objc_msgSend(a1, sel_timeoutOccurred); /*0x1b5e64*/
          }
        }
        if ( !v2 ) /*0x1b5db4*/
          break; /*0x1b5db4*/
        v6 = v2; /*0x1b5e74*/
        v5 = (const char *)objc_msgSend(a1, sel_deviceKind); /*0x1b5e85*/
        v4 = (const char *)objc_msgSend(a1, sel_name); /*0x1b5e8e*/
        IOLog((int)"%s: %s thread: msg_receive returns %d\n", v4, v5, v6);
        IOExitThread(); /*0x1b5ea1*/
      }
      if ( v8 != 2302757 ) /*0x1b5dc2*/
        break; /*0x1b5dc2*/
      objc_msgSend(a1, sel__interruptOccurred); /*0x1b5dca*/
    }
    if ( v8 == 901 ) /*0x1b5dd5*/
      break; /*0x1b5dd5*/
    if ( v8 == 900 )
    {
      v3 = objc_msgSend(a1, sel__outputChannel); /*0x1b5def*/
LABEL_9:
      objc_msgSend(a1, sel__dataPendingOccurred_, v3); /*0x1b5df4*/
    }
    else if ( v8 == 902 )
    {
      objc_msgSend(a1, sel__commandOccurred); /*0x1b5e19*/
    }
    else
    {
      IOLog((int)"Audio: unknown message id %d\n", v8);
    }
  }
  v3 = objc_msgSend(a1, sel__inputChannel); /*0x1b5ddd*/
  goto LABEL_9; /*0x1b5ddd*/
}
