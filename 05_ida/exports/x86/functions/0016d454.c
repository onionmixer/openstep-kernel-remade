/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d454. */
int __cdecl sub_16D454(_DWORD *a1)
{
  int result; // eax
  int *v2; // ebx
  int *v3; // esi
  int v4; // edx
  int v5; // edx
  int *v6; // eax
  int v7; // eax
  int v8; // [esp+Ch] [ebp-4h]

  v8 = 0; /*0x16d460*/
  result = a1[5]; /*0x16d467*/
  if ( result != 65 )
    return printf("pn_notify: msg_id = %d, unrecognized\n", a1[5]);
  v2 = (int *)dword_1E7278; /*0x16d480*/
  if ( (int *)dword_1E7278 != &dword_1E7278 )
  {
    while ( 1 )
    {
      v3 = (int *)*v2; /*0x16d494*/
      result = a1[7]; /*0x16d496*/
      v4 = v2[3]; /*0x16d499*/
      if ( result == v4 ) /*0x16d49e*/
        break; /*0x16d49e*/
      if ( v2[2] == result )
      {
        a1[4] = v4; /*0x16d4c1*/
        a1[3] = 0; /*0x16d4c4*/
        *((_BYTE *)a1 + 3) = 1; /*0x16d4cb*/
        *((_BYTE *)a1 + 24) = 2; /*0x16d4cf*/
        *((_BYTE *)a1 + 25) = 32; /*0x16d4d3*/
        a1[7] = v2[4]; /*0x16d4da*/
        v7 = msg_send(a1, 1, 0); /*0x16d4e2*/
        if ( v7 )
          printf("pn_notify: msg_send returned %d\n", v7);
        v5 = *v2; /*0x16d4fc*/
        v6 = (int *)v2[1]; /*0x16d4fe*/
        if ( (int *)*v2 == &dword_1E7278 ) /*0x16d507*/
LABEL_12:
          dword_1E727C = (int)v6; /*0x16d509*/
        else
          *(_DWORD *)(v5 + 4) = v6; /*0x16d510*/
LABEL_14:
        if ( v6 == &dword_1E7278 ) /*0x16d518*/
          dword_1E7278 = v5; /*0x16d4b4*/
        else
          *v6 = v5; /*0x16d51a*/
        result = kfree((int)v2, 0x14u); /*0x16d51f*/
        ++v8; /*0x16d524*/
      }
      v2 = v3; /*0x16d52a*/
      if ( v3 == &dword_1E7278 ) /*0x16d532*/
        goto LABEL_18; /*0x16d532*/
    }
    v5 = *v2; /*0x16d4a0*/
    v6 = (int *)v2[1]; /*0x16d4a2*/
    if ( v3 == &dword_1E7278 ) /*0x16d4ab*/
      goto LABEL_12; /*0x16d4ab*/
    v3[1] = (int)v6; /*0x16d4ad*/
    goto LABEL_14; /*0x16d4b0*/
  }
LABEL_18:
  if ( !v8 )
    return printf("pn_notify: PORT NOT FOUND\n");
  return result; /*0x16d54b*/
}
