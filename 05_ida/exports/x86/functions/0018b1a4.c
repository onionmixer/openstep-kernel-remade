/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b1a4. */
void idt_init()
{
  int v0; // ebx
  unsigned int v1; // esi
  char v2; // dl
  int v3; // edx
  int (**v4)(); // eax
  char v5; // cl
  char v6; // dl
  int v7; // edx
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v9 = 0; /*0x18b1ad*/
  v8 = 0; /*0x18b1b4*/
  do /*0x18b27f*/
  {
    v0 = *(int *)((char *)&idt_pseudo + v8 * 4); /*0x18b1bf*/
    v1 = dword_1E1A08[v8]; /*0x18b1c5*/
    v2 = BYTE2(v1) & 0x1F; /*0x18b1d0*/
    if ( (BYTE2(v1) & 0x1F) == 0xF ) /*0x18b1d6*/
    {
      v3 = *(int *)((char *)&idt_pseudo + v8 * 4); /*0x18b1da*/
      v4 = &idt[v8]; /*0x18b1e3*/
      *(_WORD *)v4 = v3; /*0x18b1e9*/
      *((_WORD *)v4 + 3) = HIWORD(v3); /*0x18b1ef*/
      *((_WORD *)v4 + 1) = v1; /*0x18b1f3*/
      v5 = 32 * ((v1 >> 21) & 3); /*0x18b202*/
      v6 = *((_BYTE *)v4 + 5) & 0x80 | 0xF; /*0x18b205*/
    }
    else if ( v2 == 14 ) /*0x18b20f*/
    {
      v7 = *(int *)((char *)&idt_pseudo + v8 * 4); /*0x18b213*/
      v4 = &idt[v8]; /*0x18b21d*/
      *(_WORD *)v4 = v7; /*0x18b223*/
      *((_WORD *)v4 + 3) = HIWORD(v7); /*0x18b229*/
      *((_WORD *)v4 + 1) = v1; /*0x18b22d*/
      v5 = 32 * ((v1 >> 21) & 3); /*0x18b23c*/
      v6 = *((_BYTE *)v4 + 5) & 0x80 | 0xE; /*0x18b23f*/
    }
    else
    {
      if ( v2 != 5 ) /*0x18b247*/
        goto LABEL_9; /*0x18b247*/
      v4 = &idt[v8]; /*0x18b250*/
      *((_WORD *)v4 + 1) = v1; /*0x18b256*/
      v5 = 32 * (v0 & 3); /*0x18b263*/
      v6 = *((_BYTE *)v4 + 5) & 0x80 | 5; /*0x18b266*/
    }
    *((_BYTE *)v4 + 5) = v5 | v6 | 0x80; /*0x18b26e*/
LABEL_9:
    v8 += 2; /*0x18b271*/
    ++v9; /*0x18b275*/
  }
  while ( v9 <= 255 ); /*0x18b27f*/
  idt_base = (int)idt; /*0x18b28b*/
  idt_limit = 2047; /*0x18b291*/
  __lidt(&idt_limit); /*0x18b29a*/
}
