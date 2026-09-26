/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3f6c. */
void __cdecl -[KeyMap _doCharGen:direction:](KeyMap *self, SEL a2, int a3, char a4)
{
  int v4; // eax
  char *v5; // ebx
  __int16 *v6; // ebx
  int v7; // edx
  int v8; // esi
  int maxMod; // ecx
  __int16 *v10; // ebx
  int v11; // ebx
  char *v12; // ebx
  int v13; // eax
  __int16 *v14; // ebx
  int v15; // edx
  int v16; // esi
  int v17; // ecx
  int v18; // edx
  __int16 *v19; // ebx
  int v20; // eax
  char *v21; // ebx
  int v22; // esi
  unsigned __int8 *v23; // ebx
  _BYTE *v24; // ebx
  id v25; // eax
  int v26; // esi
  unsigned int v27; // esi
  bool v28; // bl
  unsigned int v29; // esi
  id v30; // [esp-18h] [ebp-48h]
  int v31; // [esp+Ch] [ebp-24h]
  int v32; // [esp+10h] [ebp-20h]
  int v33; // [esp+10h] [ebp-20h]
  unsigned int v34; // [esp+14h] [ebp-1Ch]
  int v35; // [esp+18h] [ebp-18h]
  int v36; // [esp+18h] [ebp-18h]
  int v37; // [esp+1Ch] [ebp-14h]
  int v38; // [esp+1Ch] [ebp-14h]
  id v39; // [esp+20h] [ebp-10h]
  int v40; // [esp+28h] [ebp-8h]

  objc_msgSend(self->delegate, sel_setCharKeyActive_, 1); /*0x1b3f8e*/
  v40 = 11; /*0x1b3f96*/
  if ( a4 == 1 ) /*0x1b3fa1*/
    v40 = 10; /*0x1b3fa3*/
  v34 = (unsigned int)objc_msgSend(self->delegate, sel_eventFlags); /*0x1b3fc0*/
  v4 = HIWORD(v34); /*0x1b3fc3*/
  v5 = self->curMapping.keyDefs[a3]; /*0x1b3fd6*/
  if ( v5 ) /*0x1b3fe2*/
  {
    if ( self->curMapping.shorts ) /*0x1b3fc9*/
    {
      v32 = *(__int16 *)v5; /*0x1b3ff1*/
      v6 = (__int16 *)(v5 + 2); /*0x1b3ff4*/
    }
    else
    {
      v32 = (unsigned __int8)*v5; /*0x1b3fff*/
      v6 = (__int16 *)(v5 + 1); /*0x1b4002*/
    }
    if ( v32 && v4 ) /*0x1b400b*/
    {
      v7 = 2; /*0x1b400d*/
      if ( self->curMapping.shorts ) /*0x1b3fc9*/
        v7 = 4; /*0x1b4018*/
      v8 = 0; /*0x1b401d*/
      maxMod = self->curMapping.maxMod; /*0x1b4022*/
      if ( maxMod >= 0 ) /*0x1b402d*/
      {
        do /*0x1b4050*/
        {
          if ( (v32 & 1) != 0 ) /*0x1b403d*/
          {
            if ( (v4 & 1) != 0 ) /*0x1b4041*/
              v6 = (__int16 *)((char *)v6 + v7); /*0x1b4043*/
            v7 *= 2; /*0x1b4045*/
          }
          v32 >>= 1; /*0x1b4047*/
          v4 >>= 1; /*0x1b404a*/
          ++v8; /*0x1b404c*/
        }
        while ( maxMod >= v8 ); /*0x1b4050*/
      }
    }
    if ( self->curMapping.shorts ) /*0x1b3fc9*/
    {
      v37 = *v6; /*0x1b405b*/
      v10 = v6 + 1; /*0x1b405e*/
    }
    else
    {
      v37 = *(unsigned __int8 *)v6; /*0x1b4067*/
      v10 = (__int16 *)((char *)v6 + 1); /*0x1b406a*/
    }
    if ( self->curMapping.shorts ) /*0x1b3fc9*/
      v11 = *v10; /*0x1b4071*/
    else
      v11 = *(unsigned __int8 *)v10; /*0x1b4078*/
    v35 = v11; /*0x1b407b*/
    v12 = self->curMapping.keyDefs[a3]; /*0x1b4084*/
    v13 = (v34 & 0x30000) >> 16; /*0x1b4093*/
    if ( self->curMapping.shorts ) /*0x1b3fc9*/
    {
      v33 = *(__int16 *)v12; /*0x1b409f*/
      v14 = (__int16 *)(v12 + 2); /*0x1b40a2*/
    }
    else
    {
      v33 = (unsigned __int8)*v12; /*0x1b40ab*/
      v14 = (__int16 *)(v12 + 1); /*0x1b40ae*/
    }
    if ( v33 && v13 ) /*0x1b40b7*/
    {
      v15 = 2; /*0x1b40b9*/
      if ( self->curMapping.shorts ) /*0x1b3fc9*/
        v15 = 4; /*0x1b40c4*/
      v16 = 0; /*0x1b40c9*/
      v17 = self->curMapping.maxMod; /*0x1b40ce*/
      if ( v17 >= 0 ) /*0x1b40d9*/
      {
        do /*0x1b40fc*/
        {
          if ( (v33 & 1) != 0 ) /*0x1b40e9*/
          {
            if ( (v13 & 1) != 0 ) /*0x1b40ed*/
              v14 = (__int16 *)((char *)v14 + v15); /*0x1b40ef*/
            v15 *= 2; /*0x1b40f1*/
          }
          v33 >>= 1; /*0x1b40f3*/
          v13 >>= 1; /*0x1b40f6*/
          ++v16; /*0x1b40f8*/
        }
        while ( v17 >= v16 ); /*0x1b40fc*/
      }
    }
    if ( self->curMapping.shorts ) /*0x1b3fc9*/
    {
      v18 = *v14; /*0x1b4104*/
      v19 = v14 + 1; /*0x1b4107*/
    }
    else
    {
      v18 = *(unsigned __int8 *)v14; /*0x1b410c*/
      v19 = (__int16 *)((char *)v14 + 1); /*0x1b410f*/
    }
    if ( self->curMapping.shorts ) /*0x1b3fc9*/
      v20 = *v19; /*0x1b4116*/
    else
      v20 = *(unsigned __int8 *)v19; /*0x1b411c*/
    if ( self->curMapping.shorts || v37 != 255 ) /*0x1b413b*/
    {
      objc_msgSend( /*0x1b42ff*/
        self->delegate,
        sel_keyboardEvent_flags_keyCode_charCode_charSet_originalCharCode_originalCharSet_,
        v40,
        v34,
        a3,
        v35,
        v37,
        v20,
        v18);
    }
    else
    {
      v21 = self->curMapping.seqDefs[v35]; /*0x1b4147*/
      v39 = (id)v34; /*0x1b4151*/
      v22 = 0; /*0x1b4154*/
      v31 = (unsigned __int8)*v21; /*0x1b416f*/
      v23 = (unsigned __int8 *)(v21 + 1); /*0x1b4172*/
      while ( v31 > v22 ) /*0x1b4282*/
      {
        if ( v22 % 10 == 9 ) /*0x1b4185*/
          thread_block(); /*0x1b4187*/
        v38 = *v23; /*0x1b41a3*/
        v24 = v23 + 1; /*0x1b41a6*/
        if ( v38 == 255 ) /*0x1b41ae*/
        {
          if ( a4 == 1 ) /*0x1b41b8*/
          {
            v34 |= 1 << (*v24 + 16); /*0x1b41e5*/
            v23 = v24 + 1; /*0x1b41e8*/
            v30 = objc_msgSend(self->delegate, sel_deviceFlags); /*0x1b420e*/
            objc_msgSend( /*0x1b4222*/
              self->delegate,
              sel_keyboardEvent_flags_keyCode_charCode_charSet_originalCharCode_originalCharSet_,
              12,
              v30,
              a3,
              0,
              0,
              0,
              0);
          }
          else
          {
            v23 = v24 + 1; /*0x1b4230*/
          }
        }
        else
        {
          v36 = (unsigned __int8)*v24; /*0x1b424b*/
          v23 = v24 + 1; /*0x1b424e*/
          objc_msgSend( /*0x1b4276*/
            self->delegate,
            sel_keyboardEvent_flags_keyCode_charCode_charSet_originalCharCode_originalCharSet_,
            v40,
            v34,
            a3,
            v36,
            v38,
            v36,
            v38);
        }
        ++v22; /*0x1b427e*/
      }
      if ( (id)v34 != v39 ) /*0x1b428e*/
      {
        v25 = objc_msgSend(self->delegate, sel_deviceFlags); /*0x1b42ad*/
        objc_msgSend( /*0x1b42c9*/
          self->delegate,
          sel_keyboardEvent_flags_keyCode_charCode_charSet_originalCharCode_originalCharSet_,
          12,
          v25);
        v34 = (unsigned int)v39; /*0x1b42d1*/
      }
    }
  }
  if ( (self->curMapping.keyBits[a3] & 0x40) != 0 ) /*0x1b4312*/
  {
    v26 = 0; /*0x1b4318*/
    while ( a3 != self->curMapping.specialKeys[v26] ) /*0x1b432a*/
    {
      if ( ++v26 > 6 ) /*0x1b4420*/
        return; /*0x1b4420*/
    }
    objc_msgSend(self->delegate, sel_keyboardSpecialEvent_flags_keyCode_specialty_, v40, v34, a3, v26); /*0x1b434e*/
    if ( v26 == 4 && !self->curMapping.modDefs[0] && a4 == 1 ) /*0x1b4373*/
    {
      v27 = (unsigned int)objc_msgSend(self->delegate, sel_deviceFlags); /*0x1b438c*/
      v28 = (unsigned __int8)objc_msgSend(self->delegate, sel_alphaLock) == 0; /*0x1b43a9*/
      objc_msgSend(self->delegate, sel_setAlphaLock_, v28); /*0x1b43c1*/
      if ( v28 ) /*0x1b43cb*/
        v29 = v27 | 0x10000; /*0x1b43cd*/
      else
        v29 = v27 & 0xFFFEFFFF; /*0x1b43d8*/
      objc_msgSend(self->delegate, sel_setDeviceFlags_, v29); /*0x1b43f0*/
      objc_msgSend( /*0x1b4415*/
        self->delegate,
        sel_keyboardEvent_flags_keyCode_charCode_charSet_originalCharCode_originalCharSet_,
        12,
        v29,
        a3,
        0,
        0,
        0,
        0);
    }
  }
}
