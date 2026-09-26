/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c694c. */
id __cdecl -[IOSVGADisplay initFromDeviceDescription:](IOSVGADisplay *self, SEL a2, id a3)
{
  int v4; // [esp+8h] [ebp-5Ch] BYREF
  objc_super v5; // [esp+Ch] [ebp-58h] BYREF
  _BYTE v6[80]; // [esp+14h] [ebp-50h] BYREF

  v5.receiver = self; /*0x1c6962*/
  v5.super_class = (Class)stru_1FA604.ext; /*0x1c696b*/
  if ( -[IODirectDevice initFromDeviceDescription:](&v5, sel_initFromDeviceDescription_, a3) ) /*0x1c6972*/
  {
    -[IOSVGADisplay _generateName:andUnit:](self, sel__generateName_andUnit_, v6, &v4); /*0x1c69ac*/
    -[IODevice setUnit:](self, sel_setUnit_, v4); /*0x1c69bd*/
    -[IODevice setName:](self, sel_setName_, v6); /*0x1c69cb*/
    return self; /*0x1c69d0*/
  }
  else
  {
    v5.receiver = self; /*0x1c6985*/
    v5.super_class = (Class)stru_1FA604.ext; /*0x1c698e*/
    return -[IODirectDevice free](&v5, sel_free); /*0x1c6992*/
  }
}
