/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10aeac. */
int __cdecl getitimer(int a1, itimerval *a2)
{
  int result; // eax
  int v3; // ecx
  int v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  char v7; // dl
  int v8; // [esp+14h] [ebp-20h]
  _DWORD *v9; // [esp+18h] [ebp-1Ch]
  _DWORD v10[2]; // [esp+1Ch] [ebp-18h] BYREF
  int v11; // [esp+24h] [ebp-10h] BYREF
  int v12; // [esp+28h] [ebp-Ch]
  int v13; // [esp+2Ch] [ebp-8h] BYREF
  int v14; // [esp+30h] [ebp-4h]

  result = dword_1E875C; /*0x10aeb5*/
  v9 = *(_DWORD **)(dword_1E875C + 36); /*0x10aebd*/
  if ( *v9 <= 2u ) /*0x10aec3*/
  {
    v8 = splclock(); /*0x10aed5*/
    if ( *v9 ) /*0x10aedb*/
    {
      v6 = (_DWORD *)(active_u + 16 * *v9); /*0x10af6b*/
      v11 = v6[128]; /*0x10af77*/
      v12 = v6[129]; /*0x10af80*/
      v13 = v6[130]; /*0x10af89*/
      v14 = v6[131]; /*0x10af92*/
    }
    else
    {
      do /*0x10af01*/
      {
        v3 = *((_DWORD *)mtime + 1); /*0x10aef0*/
        v4 = *((_DWORD *)mtime + 2); /*0x10aef9*/
      }
      while ( *(_DWORD *)mtime != v4 ); /*0x10af01*/
      v10[0] = *((_DWORD *)mtime + 2); /*0x10af03*/
      v10[1] = v3; /*0x10af06*/
      v5 = *(_DWORD **)active_u; /*0x10af0e*/
      v11 = *(_DWORD *)(*(_DWORD *)active_u + 84); /*0x10af13*/
      v12 = v5[22]; /*0x10af19*/
      v13 = v5[23]; /*0x10af1f*/
      v14 = v5[24]; /*0x10af25*/
      if ( v13 || v14 ) /*0x10af33*/
      {
        if ( v4 > v13 || v4 == v13 && v14 < v3 ) /*0x10af42*/
        {
          v14 = 0; /*0x10af44*/
          v13 = 0; /*0x10af4b*/
        }
        else
        {
          timevalsub(&v13, v10); /*0x10af5c*/
        }
      }
    }
    splx(v8); /*0x10af99*/
    v7 = copyout(&v11, v9[1], 16); /*0x10afb0*/
    result = dword_1E875C; /*0x10afb2*/
    *(_BYTE *)(dword_1E875C + 104) = v7; /*0x10afb7*/
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10aec5*/
  }
  return result; /*0x10afbd*/
}
