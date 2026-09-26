/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1614a4. */
int __cdecl pset_add_processor(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // edx

  v2 = (_DWORD *)a1[72]; /*0x1614af*/
  if ( a1 + 71 == v2 ) /*0x1614bd*/
    a1[71] = a2; /*0x1614bf*/
  else
    v2[77] = a2; /*0x1614c8*/
  a2[78] = v2; /*0x1614ce*/
  a2[77] = a1 + 71; /*0x1614da*/
  a1[72] = a2; /*0x1614e0*/
  a2[75] = a1; /*0x1614e6*/
  ++a1[73]; /*0x1614ec*/
  return quantum_set(a1); /*0x1614fb*/
}
