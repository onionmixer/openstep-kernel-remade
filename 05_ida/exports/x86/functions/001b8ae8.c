/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8ae8. */
id __cdecl -[AudioStream createSndReplyMsg](AudioStream *self, SEL a2)
{
  if ( !self->sndReplyMsg ) /*0x1b8aef*/
    self->sndReplyMsg = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)IOMalloc(0x2000u); /*0x1b8aff*/
  *((_BYTE *)self->sndReplyMsg + 3) = 1; /*0x1b8b05*/
  *((_DWORD *)self->sndReplyMsg + 1) = 24; /*0x1b8b0c*/
  *((_DWORD *)self->sndReplyMsg + 2) = 0; /*0x1b8b16*/
  *((_DWORD *)self->sndReplyMsg + 3) = 0; /*0x1b8b20*/
  *((_DWORD *)self->sndReplyMsg + 4) = 0; /*0x1b8b2a*/
  *((_DWORD *)self->sndReplyMsg + 5) = 0; /*0x1b8b34*/
  return self; /*0x1b8b3d*/
}
