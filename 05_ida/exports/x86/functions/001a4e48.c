/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4e48. */
int __cdecl +[IODevice addLoadedClass:description:](id a1, SEL a2, id a3, id a4)
{
  id v4; // eax
  _DWORD *v5; // eax
  int v6; // edi
  int v7; // esi
  _DWORD *v8; // ebx
  char v10; // [esp+Ch] [ebp-10h]
  _DWORD *v11; // [esp+10h] [ebp-Ch]
  id v12; // [esp+14h] [ebp-8h] BYREF
  int *v13; // [esp+18h] [ebp-4h] BYREF

  v10 = 0; /*0x1a4e51*/
  if ( !sub_1A3E30((int)a3, &v13) ) /*0x1a4e5d*/
    v13[4] = (int)a4; /*0x1a4e6f*/
  v4 = objc_msgSend(a3, sel_deviceStyle); /*0x1a4e7d*/
  if ( v4 == (id)1 )
  {
    v5 = objc_msgSend(a3, sel_requiredProtocols); /*0x1a4eab*/
    v11 = v5; /*0x1a4eb0*/
    if ( v5 && *v5 ) /*0x1a4eba*/
    {
      v6 = 0; /*0x1a4ee0*/
      do /*0x1a4f68*/
      {
        v7 = sub_1A3D58(v6, &v12); /*0x1a4eee*/
        if ( !v7 ) /*0x1a4ef9*/
        {
          if ( *v11 ) /*0x1a4f04*/
          {
            v8 = v11; /*0x1a4f09*/
            while ( (unsigned __int8)objc_msgSend(v12, sel_conformsTo_, *v8) ) /*0x1a4f24*/
            {
              if ( !*++v8 ) /*0x1a4f29*/
                goto LABEL_16; /*0x1a4f2c*/
            }
          }
          else
          {
LABEL_16:
            objc_msgSend(a4, sel_setDirectDevice_, v12); /*0x1a4f2e*/
            if ( (unsigned __int8)objc_msgSend(a3, sel_probe_, a4) ) /*0x1a4f51*/
              v10 = 1; /*0x1a4f5d*/
          }
        }
        ++v6; /*0x1a4f61*/
      }
      while ( v7 != -704 ); /*0x1a4f68*/
    }
    else
    {
      objc_msgSend(a3, sel_name); /*0x1a4eca*/
      IOLog("Loaded class %s returns nil for +requiredProtocols\n"); /*0x1a4ed5*/
    }
  }
  else if ( !v4 || v4 == (id)2 )
  {
    if ( (unsigned __int8)objc_msgSend(a3, sel_respondsTo_, sel_probe_) )
    {
      if ( (unsigned __int8)objc_msgSend(a3, sel_probe_, a4) ) /*0x1a4fbb*/
        v10 = 1; /*0x1a4fc4*/
    }
    else
    {
      objc_msgSend(a3, sel_name); /*0x1a4f99*/
      IOLog("addLoadedClass: Class %s does not respond to probe:\n");
    }
  }
  if ( v10 ) /*0x1a4fcc*/
    return 0; /*0x1a4fd8*/
  else
    return -704; /*0x1a4fce*/
}
