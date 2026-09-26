/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4fe4. */
void __cdecl +[IODevice connectToIndirectDevices:](id a1, SEL a2, id a3)
{
  int v3; // esi
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  id v7; // ebx
  id v8; // eax
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0; /*0x1a4ff0*/
  objc_msgSend(dword_1E8684, sel_lock); /*0x1a5000*/
  while ( 1 ) /*0x1a500d*/
  {
    v4 = sub_1A3EAC(v3, &v9); /*0x1a500d*/
    if ( v4 == -704 ) /*0x1a501a*/
      break; /*0x1a501a*/
    if ( v4 != -727 && objc_msgSend(*(id *)v9, sel_deviceStyle) == (id)1 ) /*0x1a5045*/
    {
      v5 = objc_msgSend(*(id *)v9, sel_requiredProtocols); /*0x1a5058*/
      if ( v5 && *v5 ) /*0x1a5064*/
      {
        v6 = v5; /*0x1a5090*/
        while ( (unsigned __int8)objc_msgSend(a3, sel_conformsTo_, *v6) ) /*0x1a50a9*/
        {
          if ( !*++v6 ) /*0x1a50b2*/
          {
            if ( *(_DWORD *)(v9 + 16) ) /*0x1a50ba*/
            {
              v7 = *(id *)(v9 + 16); /*0x1a50c1*/
            }
            else
            {
              v8 = objc_msgSend(&aIodevicedescri_0, sel_alloc); /*0x1a50dd*/
              v7 = objc_msgSend(v8, sel_init); /*0x1a50eb*/
            }
            objc_msgSend(v7, sel_setDirectDevice_, a3); /*0x1a50c3*/
            objc_msgSend(dword_1E8684, sel_unlock); /*0x1a510c*/
            if ( !(unsigned __int8)objc_msgSend(*(id *)v9, sel_probe_, v7) ) /*0x1a511f*/
              objc_msgSend(v7, sel_free); /*0x1a5133*/
            objc_msgSend(dword_1E8684, sel_lock); /*0x1a5149*/
            break; /*0x1a5149*/
          }
        }
      }
      else
      {
        objc_msgSend(*(id *)v9, sel_name); /*0x1a5076*/
        IOLog("Loaded class %s returns nil for +requiredProtocols\n"); /*0x1a5081*/
      }
    }
    ++v3; /*0x1a5151*/
  }
  objc_msgSend(dword_1E8684, sel_unlock); /*0x1a5166*/
}
