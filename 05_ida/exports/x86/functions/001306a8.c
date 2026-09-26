/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1306a8. */
int __cdecl sub_1306A8(const char *a1, char *__dst, _WORD *a3, char *a4)
{
  int result; // eax
  unsigned int v5; // eax
  unsigned int v6; // ebx
  int v7; // esi
  int i; // [esp+Ch] [ebp-54h]
  int v9; // [esp+18h] [ebp-48h] BYREF
  char v10; // [esp+1Ch] [ebp-44h] BYREF
  _DWORD v11[4]; // [esp+20h] [ebp-40h] BYREF
  _DWORD v12[6]; // [esp+30h] [ebp-30h] BYREF
  _DWORD v13[2]; // [esp+48h] [ebp-18h] BYREF
  char *__src; // [esp+50h] [ebp-10h] BYREF
  int v15; // [esp+54h] [ebp-Ch]
  _BYTE v16[4]; // [esp+58h] [ebp-8h] BYREF
  char *v17; // [esp+5Ch] [ebp-4h]

  v13[0] = hostname; /*0x1306bf*/
  v13[1] = a1; /*0x1306c9*/
  bzero(&__src, 0x10u); /*0x1306d2*/
  result = sub_130344(); /*0x1306d7*/
  if ( !result )
  {
    __src = (char *)kalloc(0x100u); /*0x1306f1*/
    v17 = (char *)kalloc(0x100u); /*0x1306fe*/
    for ( i = 0; i <= 4; ++i ) /*0x130701*/
    {
      word_1E59DA = __ROR2__(111, 8); /*0x130715*/
      v5 = clntkudp_create(&unk_1E59D8, 100000, 2, 5, *(_DWORD *)(active_u + 28)); /*0x130734*/
      v6 = v5; /*0x130739*/
      if ( !v5 ) /*0x130740*/
        panic(aPmapRmtcallCln); /*0x130747*/
      v12[0] = 100026; /*0x13074f*/
      v12[1] = 1; /*0x130756*/
      v12[2] = 2; /*0x13075d*/
      v12[4] = v13; /*0x130767*/
      v12[5] = xdr_bp_getfile_arg; /*0x13076a*/
      v11[0] = &v10; /*0x130774*/
      v11[2] = &__src; /*0x13077a*/
      v11[3] = xdr_bp_getfile_res; /*0x13077d*/
      v7 = clntkudp_callit_addr(v5, 5, xdr_rmtcall_args, v12, xdr_rmtcallres, v11, 5, 0, 0); /*0x1307a6*/
      (*(void (__cdecl **)(unsigned int))(*(_DWORD *)(v6 + 4) + 16))(v6); /*0x1307b2*/
      if ( v7 != 5 ) /*0x1307ba*/
        break; /*0x1307ba*/
    }
    if ( !v7 ) /*0x1307cb*/
    {
      strcpy(__dst, __src); /*0x1307d5*/
      strcpy(a4, v17); /*0x1307e2*/
    }
    kfree((int)__src, 0x100u); /*0x1307f3*/
    kfree((int)v17, 0x100u); /*0x130801*/
    if ( v7 )
    {
      result = 60; /*0x13080d*/
      if ( v7 != 5 ) /*0x130815*/
        return v7; /*0x13081b*/
    }
    else
    {
      bcopy(v16, &v9, 4u); /*0x13082e*/
      if ( *__dst && *a4 && v9 )
      {
        if ( v15 == 1 )
        {
          bzero(a3, 0x10u); /*0x130876*/
          *a3 = 2; /*0x13087e*/
          *((_DWORD *)a3 + 1) = v9; /*0x130886*/
          printf("NFS mounting \"%s\" from  %s:%s\n", a1, __dst, a4); /*0x13089d*/
          return 0; /*0x1308a2*/
        }
        else
        {
          printf("getfile: unknown address type %d\n", v15);
          return 43; /*0x130867*/
        }
      }
      else
      {
        return 22; /*0x13084c*/
      }
    }
  }
  return result; /*0x1308a7*/
}
