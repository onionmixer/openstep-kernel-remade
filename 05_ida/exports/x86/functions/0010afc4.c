/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10afc4. */
int __cdecl setitimer(int a1, const itimerval *a2, itimerval *a3)
{
  int result; // eax
  int v4; // ecx
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  char v7; // dl
  int v8; // esi
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // [esp+10h] [ebp-50h]
  int v12; // [esp+1Ch] [ebp-44h]
  _DWORD *v13; // [esp+20h] [ebp-40h]
  _DWORD *v14; // [esp+24h] [ebp-3Ch]
  int v15; // [esp+28h] [ebp-38h]
  _DWORD *v16; // [esp+2Ch] [ebp-34h]
  _DWORD v17[2]; // [esp+30h] [ebp-30h] BYREF
  _DWORD v18[2]; // [esp+38h] [ebp-28h] BYREF
  int v19; // [esp+40h] [ebp-20h] BYREF
  int v20; // [esp+44h] [ebp-1Ch]
  int v21; // [esp+48h] [ebp-18h] BYREF
  int v22; // [esp+4Ch] [ebp-14h]
  int v23; // [esp+50h] [ebp-10h] BYREF
  int v24; // [esp+54h] [ebp-Ch]
  int v25; // [esp+58h] [ebp-8h] BYREF
  int v26; // [esp+5Ch] [ebp-4h]

  v16 = *(_DWORD **)(dword_1E875C + 36); /*0x10afd6*/
  result = *(_DWORD *)active_u; /*0x10afde*/
  v14 = *(_DWORD **)active_u; /*0x10afe0*/
  if ( *v16 <= 2u ) /*0x10afe6*/
  {
    v15 = v16[1]; /*0x10affa*/
    result = v16[2]; /*0x10b000*/
    if ( result ) /*0x10b005*/
    {
      v16[1] = result; /*0x10b00b*/
      result = dword_1E875C; /*0x10b00e*/
      v13 = *(_DWORD **)(dword_1E875C + 36); /*0x10b016*/
      if ( *v13 <= 2u ) /*0x10b01c*/
      {
        v12 = splclock(); /*0x10b02d*/
        if ( *v13 ) /*0x10b033*/
        {
          v6 = (_DWORD *)(active_u + 16 * *v13); /*0x10b0c7*/
          v19 = v6[128]; /*0x10b0d3*/
          v20 = v6[129]; /*0x10b0dc*/
          v21 = v6[130]; /*0x10b0e5*/
          v22 = v6[131]; /*0x10b0ee*/
        }
        else
        {
          do /*0x10b059*/
          {
            v11 = *((_DWORD *)mtime + 1); /*0x10b04b*/
            v4 = *((_DWORD *)mtime + 2); /*0x10b051*/
          }
          while ( *(_DWORD *)mtime != v4 ); /*0x10b059*/
          v18[0] = *((_DWORD *)mtime + 2); /*0x10b05b*/
          v18[1] = v11; /*0x10b061*/
          v5 = *(_DWORD **)active_u; /*0x10b069*/
          v19 = *(_DWORD *)(*(_DWORD *)active_u + 84); /*0x10b06e*/
          v20 = v5[22]; /*0x10b074*/
          v21 = v5[23]; /*0x10b07a*/
          v22 = v5[24]; /*0x10b080*/
          if ( v21 || v22 ) /*0x10b08e*/
          {
            if ( v4 > v21 || v4 == v21 && v22 < v11 ) /*0x10b09d*/
            {
              v22 = 0; /*0x10b09f*/
              v21 = 0; /*0x10b0a6*/
            }
            else
            {
              timevalsub(&v21, v18); /*0x10b0b8*/
            }
          }
        }
        splx(v12); /*0x10b0f5*/
        v7 = copyout(&v19, v13[1], 16); /*0x10b10c*/
        result = dword_1E875C; /*0x10b10e*/
        *(_BYTE *)(dword_1E875C + 104) = v7; /*0x10b113*/
      }
      else
      {
        *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10b01e*/
      }
    }
    if ( v15 ) /*0x10b11d*/
    {
      *(_BYTE *)(dword_1E875C + 104) = copyin(v15, &v23, 16); /*0x10b139*/
      result = dword_1E875C; /*0x10b13c*/
      if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10b144*/
      {
        if ( itimerfix(&v25) || itimerfix(&v23) ) /*0x10b15f*/
        {
          result = dword_1E875C; /*0x10b16b*/
          *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10b170*/
        }
        else
        {
          v8 = splclock(); /*0x10b181*/
          if ( *v16 ) /*0x10b186*/
          {
            v10 = (_DWORD *)(active_u + 16 * *v16); /*0x10b213*/
            v10[128] = v23; /*0x10b21c*/
            v10[129] = v24; /*0x10b225*/
            v10[130] = v25; /*0x10b22e*/
            v10[131] = v26; /*0x10b237*/
          }
          else
          {
            do /*0x10b1a9*/
              v9 = *((_DWORD *)mtime + 1); /*0x10b19d*/
            while ( *(_DWORD *)mtime != *((_DWORD *)mtime + 2) ); /*0x10b1a9*/
            v17[0] = *((_DWORD *)mtime + 2); /*0x10b1ab*/
            v17[1] = v9; /*0x10b1ae*/
            untimeout((int)realitexpire, (int)v14); /*0x10b1ba*/
            if ( v25 || v26 ) /*0x10b1cc*/
            {
              timevaladd(&v25, v17); /*0x10b1d6*/
              hzto(&v25); /*0x10b1dc*/
              timeout((int)realitexpire); /*0x10b1eb*/
            }
            v14[21] = v23; /*0x10b1f9*/
            v14[22] = v24; /*0x10b1ff*/
            v14[23] = v25; /*0x10b205*/
            v14[24] = v26; /*0x10b20b*/
          }
          return splx(v8); /*0x10b23e*/
        }
      }
    }
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10afe8*/
  }
  return result; /*0x10b246*/
}
