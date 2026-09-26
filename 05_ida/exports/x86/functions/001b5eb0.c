/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b5eb0. */
void __cdecl __noreturn sub_1B5EB0(id a1)
{
  int v1; // eax
  Class v2; // ebx
  id v3; // ebx
  id v4; // esi
  id v5; // eax
  id v6; // eax
  int v7; // eax
  int v8; // [esp+Ch] [ebp-3Ch]
  _DWORD v9[5]; // [esp+10h] [ebp-38h] BYREF
  int v10; // [esp+24h] [ebp-24h]
  int v11; // [esp+2Ch] [ebp-1Ch]
  int v12; // [esp+34h] [ebp-14h]
  int v13; // [esp+3Ch] [ebp-Ch]

  v1 = task_self(); /*0x1b5ebd*/
  if ( port_allocate_EXTERNAL(v1) )
    IOLog((int)"Audio: port_allocate");
  v2 = objc_lookUpClass("EventDriver"); /*0x1b5ee9*/
  if ( !v2 )
  {
    IOLog((int)"Audio: objc_lookUpClass failure\n");
    IOExitThread(); /*0x1b5efc*/
  }
  v3 = -[objc_class instance](v2, sel_instance); /*0x1b5f11*/
  v4 = objc_msgSend(v3, sel_ev_port); /*0x1b5f20*/
  v5 = objc_msgSend(v3, sel_setSpecialKeyPort_keyFlavor_keyPort_, v4, 0); /*0x1b5f2e*/
  if ( v5 )
  {
    IOLog((int)"Audio: SetSpecialKeyPort error %d\n", v5);
    IOExitThread(); /*0x1b5f45*/
  }
  v6 = objc_msgSend(v3, sel_setSpecialKeyPort_keyFlavor_keyPort_, v4, 1); /*0x1b5f59*/
  if ( v6 )
  {
    IOLog((int)"Audio: SetSpecialKeyPort error %d\n", v6);
    IOExitThread(); /*0x1b5f70*/
  }
  while ( 1 )
  {
    v9[3] = v8; /*0x1b5f78*/
    v9[1] = 56; /*0x1b5f7b*/
    v7 = msg_receive(v9, 0, 0); /*0x1b5f8a*/
    if ( v7 )
    {
      IOLog((int)"Audio: keyThread msg_receive error: %d\n", v7);
      IOExitThread(); /*0x1b5fa1*/
    }
    if ( v10 != 1399547257 )
    {
      IOLog((int)"Audio: unknown msg id %d in keyThread\n", v10);
      IOExitThread(); /*0x1b5fbe*/
    }
    objc_msgSend(a1, sel__keyOccurred_event_flags_, v11, v12, v13); /*0x1b5fdd*/
  }
}
