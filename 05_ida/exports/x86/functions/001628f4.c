/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1628f4. */
void sub_1628F4()
{
  _WORD *v0; // ebx
  int v1; // edx
  _BYTE v2[20]; // [esp+Ch] [ebp-30h] BYREF
  _BYTE v3[12]; // [esp+20h] [ebp-1Ch] BYREF
  int v4; // [esp+2Ch] [ebp-10h]
  int v5; // [esp+30h] [ebp-Ch]
  __int16 v6; // [esp+36h] [ebp-6h]
  __int16 v7; // [esp+38h] [ebp-4h]

  if ( dword_1E6448 ) /*0x16290a*/
    kdp_panic(aKdpPoll); /*0x162911*/
  dword_1E6440 = 0; /*0x162919*/
  kdp_en_recv_pkt(&unk_1E5E54, &dword_1E6444, 3); /*0x16292f*/
  if ( (unsigned int)dword_1E6444 >= 0x2A ) /*0x16293e*/
  {
    v0 = (_WORD *)((char *)&unk_1E5E54 + dword_1E6440); /*0x162952*/
    v1 = dword_1E6440 + 14; /*0x162958*/
    dword_1E6440 += 14; /*0x16295b*/
    if ( __ROR2__(v0[6], 8) == 2048 ) /*0x16296d*/
    {
      bcopy((char *)&unk_1E5E54 + v1, v3, 0x1Cu); /*0x16297d*/
      bcopy((const void *)(dword_1E6440 + 1990228), v2, 0x14u); /*0x162990*/
      dword_1E6440 += 28; /*0x162995*/
      if ( v3[9] == 17 && (v2[0] & 0xFu) <= 5 && __ROR2__(v6, 8) == 1139 ) /*0x1629bc*/
      {
        if ( !dword_1F66A8 ) /*0x1629c5*/
        {
          bcopy(v0, &unk_1F66C4, 6u); /*0x1629cf*/
          adr = v5; /*0x1629da*/
          bcopy(v0 + 3, &unk_1F66D0, 6u); /*0x1629eb*/
          dword_1F66CC = v4; /*0x1629f3*/
        }
        dword_1E6444 = (unsigned __int16)__ROR2__(v7, 8) - 8; /*0x162a09*/
        dword_1E6448 = 1; /*0x162a0e*/
      }
    }
  }
}
