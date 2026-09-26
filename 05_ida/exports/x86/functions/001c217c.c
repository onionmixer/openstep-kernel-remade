/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c217c. */
id *__cdecl -[IOPCMCIADeviceDescription tupleList](IOPCMCIADeviceDescription *self, SEL a2)
{
  void *pcmcia_private; // esi
  id v3; // eax
  id v4; // eax
  void *v5; // edi
  id v6; // eax
  unsigned int i; // ebx
  IOPCMCIATuple *v8; // eax

  pcmcia_private = self->_pcmcia_private; /*0x1c2185*/
  if ( !*((_DWORD *)pcmcia_private + 1) ) /*0x1c2188*/
  {
    v3 = -[IOPCMCIADeviceDescription _delegate](self, sel__delegate); /*0x1c21a6*/
    v4 = objc_msgSend(v3, sel_resourcesForKey_); /*0x1c21af*/
    v5 = v4; /*0x1c21b4*/
    if ( v4 ) /*0x1c21bb*/
    {
      v6 = objc_msgSend(v4, sel_count); /*0x1c21c5*/
      *(_DWORD *)pcmcia_private = v6; /*0x1c21ca*/
      *((_DWORD *)pcmcia_private + 1) = IOMalloc(4 * (_DWORD)v6); /*0x1c21d5*/
      for ( i = 0; *(_DWORD *)pcmcia_private > i; ++i ) /*0x1c21dd*/
      {
        objc_msgSend(v5, sel_objectAt_, i); /*0x1c21ed*/
        v8 = +[Object alloc](aIopcmciatuple, sel_alloc); /*0x1c2208*/
        *(_DWORD *)(*((_DWORD *)pcmcia_private + 1) + 4 * i) = -[IOPCMCIATuple initWithKernTuple:]( /*0x1c221b*/
                                                                 v8,
                                                                 sel_initWithKernTuple_);
      }
    }
  }
  return *((id **)pcmcia_private + 1); /*0x1c222c*/
}
