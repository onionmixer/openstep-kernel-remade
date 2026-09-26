/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9160. */
int sub_1B9160()
{
  _DWORD *v0; // esi
  int v1; // ebx
  int v2; // eax
  int *v3; // edi
  int v4; // ecx
  int v5; // eax
  int v7; // [esp+Ch] [ebp-20h]
  id v8; // [esp+14h] [ebp-18h]
  int v9; // [esp+18h] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+20h] [ebp-Ch]
  int v13; // [esp+20h] [ebp-Ch]
  int v14; // [esp+24h] [ebp-8h] BYREF
  int v15; // [esp+28h] [ebp-4h]

  v0 = (_DWORD *)IOMalloc(0x28u); /*0x1b9170*/
  v1 = 0; /*0x1b9172*/
  v8 = nullptr; /*0x1b9174*/
  v7 = 0; /*0x1b917b*/
  v9 = dword_1E53A4; /*0x1b9188*/
  objc_msgSend(dword_1E53A8, sel_unlock); /*0x1b9199*/
  while ( 1 )
  {
    while ( 1 )
    {
      v0[3] = v9; /*0x1b91a7*/
      v0[1] = 40; /*0x1b91aa*/
      v2 = v1 <= 0 ? msg_receive(v0, 0, 0) : msg_receive(v0, 256, v1);
      if ( v2 != -203 ) /*0x1b91d2*/
        break; /*0x1b91d2*/
LABEL_6:
      objc_msgSend(v8, sel_control_, v7); /*0x1b91d4*/
      v1 = 0; /*0x1b91e8*/
    }
    if ( v2 || v0[5] ) /*0x1b91f4*/
      return IOExitThread(); /*0x1b9298*/
    v8 = (id)v0[7]; /*0x1b9201*/
    v7 = v0[8]; /*0x1b9207*/
    v3 = (int *)v0[9]; /*0x1b920a*/
    v10 = *v3; /*0x1b9212*/
    v12 = v3[1]; /*0x1b9215*/
    microtime(&v14); /*0x1b921c*/
    v4 = v10 - v14; /*0x1b9227*/
    v11 = v10 - v14; /*0x1b922a*/
    v5 = v12 - v15; /*0x1b9230*/
    v13 = v12 - v15; /*0x1b9233*/
    if ( v13 < 0 ) /*0x1b9236*/
    {
      v11 = v4 - 1; /*0x1b9239*/
      v13 = v5 + 1000000; /*0x1b9241*/
    }
    v1 = v13 / 1000 + 1000 * v11; /*0x1b9267*/
    if ( v1 <= 0 ) /*0x1b926c*/
      goto LABEL_6; /*0x1b926c*/
  }
}
