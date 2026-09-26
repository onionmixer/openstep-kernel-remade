/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c5fe4. */
int __cdecl -[IOSVGADisplay _registerWithED](IOSVGADisplay *self, SEL a2)
{
  id v2; // eax
  id v3; // esi
  $E63760587FADDAA675F803BB3FBE6402 *v4; // eax
  $E63760587FADDAA675F803BB3FBE6402 *v5; // ebx
  const char *v7; // eax
  id v8; // eax
  size_t v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  v2 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1c6015*/
  v3 = objc_msgSend(v2, sel_registerScreen_bounds_shmem_size_); /*0x1c6023*/
  v4 = -[IOSVGADisplay _shmem](self, sel__shmem); /*0x1c602d*/
  v5 = v4; /*0x1c6032*/
  if ( v3 == (id)-1 ) /*0x1c603a*/
    return -706; /*0x1c603c*/
  if ( v9 <= 0x1448 )
  {
    bzero(v4, v9); /*0x1c60a2*/
    *((_BYTE *)v5 + 8) = 1; /*0x1c60a7*/
    *((_DWORD *)v5 + 12) = v10; /*0x1c60ae*/
    *((_DWORD *)v5 + 13) = v11; /*0x1c60b4*/
    -[IODisplay setToken:](self, sel_setToken_, v3); /*0x1c60c0*/
    return 0; /*0x1c60c5*/
  }
  else
  {
    v7 = -[IODevice name](self, sel_name); /*0x1c6061*/
    IOLog((int)"%s: shmem_size > sizeof (VGAShmem_t)(%d<>%d)\n", v7, v9, 5192);
    v8 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1c608a*/
    objc_msgSend(v8, sel_unregisterScreen_); /*0x1c6093*/
    return -706; /*0x1c6098*/
  }
}
