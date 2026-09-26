/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1964dc. */
id __cdecl -[kmDevice initKb](kmDevice *self, SEL a2)
{
  int v2; // eax
  id v4; // eax
  id v5; // eax

  v2 = IOGetObjectForDeviceName(aPckeyboard0, (int)&self->kbId); /*0x1964ef*/
  if ( v2 ) /*0x1964f9*/
  {
    -[IODevice stringFromReturn:](self, sel_stringFromReturn_, v2); /*0x196504*/
    IOLog(aKmInitCanTFind); /*0x19650f*/
    return nullptr; /*0x196514*/
  }
  else
  {
    v4 = objc_msgSend(self->kbId, sel_becomeOwner_, self); /*0x196527*/
    if ( v4 ) /*0x196531*/
    {
      -[IODevice stringFromReturn:](self, sel_stringFromReturn_, v4); /*0x19653c*/
      IOLog(aKmInitBecomeow); /*0x196547*/
      return nullptr; /*0x19654c*/
    }
    else
    {
      v5 = objc_msgSend(self->kbId, sel_desireOwnership_, self); /*0x19655f*/
      if ( v5 ) /*0x196569*/
      {
        -[IODevice stringFromReturn:](self, sel_stringFromReturn_, v5); /*0x196574*/
        IOLog(aKmInitDesireow); /*0x19657f*/
        return nullptr; /*0x196584*/
      }
      else
      {
        return self; /*0x196588*/
      }
    }
  }
}
