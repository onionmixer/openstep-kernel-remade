/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c4c6c. */
int __cdecl -[IOFrameBufferDisplay _registerWithED](IOFrameBufferDisplay *self, SEL a2)
{
  id v2; // eax
  id v3; // esi
  void *priv; // ebx
  const char *v6; // eax
  id v7; // eax
  size_t __len; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v2 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1c4c9d*/
  v3 = objc_msgSend(v2, sel_registerScreen_bounds_shmem_size_); /*0x1c4cab*/
  priv = self->priv; /*0x1c4cad*/
  if ( v3 == (id)-1 ) /*0x1c4cb9*/
    return -706; /*0x1c4cbb*/
  if ( __len <= 0x1448 )
  {
    memset(priv, 0, __len); /*0x1c4d24*/
    *((_BYTE *)priv + 8) = 1; /*0x1c4d29*/
    *((_DWORD *)priv + 12) = v9; /*0x1c4d30*/
    *((_DWORD *)priv + 13) = v10; /*0x1c4d36*/
    -[IODisplay setToken:](self, sel_setToken_, v3); /*0x1c4d42*/
    return 0; /*0x1c4d47*/
  }
  else
  {
    v6 = -[IODevice name](self, sel_name); /*0x1c4ce1*/
    IOLog((int)"%s: shmem_size > sizeof (StdFBShmem_t)(%d<>%d)\n", v6, __len, 5192);
    v7 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1c4d0a*/
    objc_msgSend(v7, sel_unregisterScreen_); /*0x1c4d13*/
    return -706; /*0x1c4d18*/
  }
}
