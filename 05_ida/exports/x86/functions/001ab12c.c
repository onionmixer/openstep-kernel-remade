/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab12c. */
int __cdecl -[IOTokenRing _getInstanceTable:](IOTokenRing *self, SEL a2, id a3)
{
  const char *v3; // eax
  const char *v5; // ebx
  const char *v6; // esi
  const char *v7; // edi
  int v8; // ecx
  bool v9; // zf
  int v10; // eax
  const char *v11; // eax
  id v12; // eax
  _BYTE *v13; // ebx
  _BYTE *v14; // esi
  const char *v15; // edi
  int v16; // ecx
  bool v17; // zf
  int v18; // eax
  _BYTE *v19; // ebx
  _BYTE *v20; // esi
  const char *v21; // edi
  int v22; // ecx
  bool v23; // zf
  int v24; // eax
  id v25; // [esp-Ch] [ebp-1Ch]
  id v26; // [esp+Ch] [ebp-4h]

  v26 = objc_msgSend(a3, sel_configTable); /*0x1ab145*/
  if ( v26 )
  {
    v5 = (const char *)objc_msgSend(v26, sel_valueForStringKey_, "Ring Speed"); /*0x1ab19d*/
    v6 = v5; /*0x1ab19f*/
    v7 = "4"; /*0x1ab1a1*/
    v8 = 2; /*0x1ab1a6*/
    v10 = 0; /*0x1ab1ac*/
    v9 = 1; /*0x1ab1ac*/
    do /*0x1ab1ae*/
    {
      if ( !v8 ) /*0x1ab1ae*/
        break; /*0x1ab1ae*/
      v9 = *v6++ == *v7++; /*0x1ab1ae*/
      --v8; /*0x1ab1ae*/
    }
    while ( v9 ); /*0x1ab1ae*/
    if ( !v9 ) /*0x1ab1b0*/
      v10 = *((unsigned __int8 *)v6 - 1) - *((unsigned __int8 *)v7 - 1); /*0x1ab1ba*/
    if ( v10 )
    {
      if ( strcmp(v5, "16") )
      {
        v11 = -[IODevice name](self, sel_name); /*0x1ab203*/
        IOLog((int)"%s: invalid ring speed in Instance.table\n", v11);
      }
      self->_ringSpeed = 16; /*0x1ab1ea*/
    }
    else
    {
      self->_ringSpeed = 4; /*0x1ab1c6*/
    }
    objc_msgSend(v26, sel_freeString_, v5); /*0x1ab22f*/
    v12 = objc_msgSend(v26, sel_valueForStringKey_, "Node Address"); /*0x1ab244*/
    objc_msgSend(v26, sel_freeString_, v12); /*0x1ab257*/
    v13 = objc_msgSend(v26, sel_valueForStringKey_, "16Mb Early Token"); /*0x1ab274*/
    v14 = v13; /*0x1ab276*/
    v15 = "YES"; /*0x1ab278*/
    v16 = 4; /*0x1ab27d*/
    v18 = 0; /*0x1ab283*/
    v17 = 1; /*0x1ab283*/
    do /*0x1ab285*/
    {
      if ( !v16 ) /*0x1ab285*/
        break; /*0x1ab285*/
      v17 = *v14++ == *v15++; /*0x1ab285*/
      --v16; /*0x1ab285*/
    }
    while ( v17 ); /*0x1ab285*/
    if ( !v17 ) /*0x1ab287*/
      v18 = (unsigned __int8)*(v14 - 1) - *((unsigned __int8 *)v15 - 1); /*0x1ab291*/
    if ( v18 ) /*0x1ab298*/
      *(_BYTE *)&self->_flags &= ~2u; /*0x1ab2ab*/
    else
      *(_BYTE *)&self->_flags |= 2u; /*0x1ab29d*/
    objc_msgSend(v26, sel_freeString_, v13); /*0x1ab2be*/
    v19 = objc_msgSend(v26, sel_valueForStringKey_, "Auto Recovery"); /*0x1ab2d8*/
    v20 = v19; /*0x1ab2da*/
    v21 = "YES"; /*0x1ab2dc*/
    v22 = 4; /*0x1ab2e1*/
    v24 = 0; /*0x1ab2e7*/
    v23 = 1; /*0x1ab2e7*/
    do /*0x1ab2e9*/
    {
      if ( !v22 ) /*0x1ab2e9*/
        break; /*0x1ab2e9*/
      v23 = *v20++ == *v21++; /*0x1ab2e9*/
      --v22; /*0x1ab2e9*/
    }
    while ( v23 ); /*0x1ab2e9*/
    if ( !v23 ) /*0x1ab2eb*/
      v24 = (unsigned __int8)*(v20 - 1) - *((unsigned __int8 *)v21 - 1); /*0x1ab2f5*/
    if ( v24 ) /*0x1ab2fc*/
      *(_BYTE *)&self->_flags &= ~4u; /*0x1ab30f*/
    else
      *(_BYTE *)&self->_flags |= 4u; /*0x1ab301*/
    objc_msgSend(v26, sel_freeString_, v19); /*0x1ab322*/
    *(_BYTE *)&self->_flags |= 8u; /*0x1ab32a*/
    self->_ipMtu = 8100; /*0x1ab331*/
    self->_ipTokenPriority = 8; /*0x1ab33b*/
    *(_BYTE *)&self->_flags |= 0x20u; /*0x1ab345*/
    ipforwarding = 0; /*0x1ab34c*/
    return 0; /*0x1ab356*/
  }
  else
  {
    v25 = -[IODevice unit](self, sel_unit); /*0x1ab15f*/
    v3 = -[IODevice name](self, sel_name); /*0x1ab16b*/
    IOLog((int)"%s: couldn't get Instance%d.table\n", v3, v25);
    return 1; /*0x1ab17e*/
  }
}
