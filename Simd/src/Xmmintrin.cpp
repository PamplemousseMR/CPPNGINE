#include "Simd.h"

#include <xmmintrin.h>
#include <iostream>

/*  xmmintrin
SSE
Introduce eight/sixteen 128 bit registers (XMM0-XMM7/15) and instruction to work with four single precision floating point operands.
Add integer operations on MMX registers too.
The MMX-integer part of SSE is sometimes called MMXEXT, and was implemented on a few non-Intel CPUs without xmm registers and the floating point part of SSE.
*/
void xmmintrin()
{
	float aligned32 arrFloat4[4];
	__m128 m128a, m128b;
	__m64 m64;
	const float cf = 10.5f;
	const char cc = 'a';
	float flo = 10.5f;
	int in = 10;
	unsigned ui = 10;
#ifdef _M_X64
    __int64 i64;
#endif
#ifdef _M_X86
    char aligned32 arrChar4[4];
#endif

	/*
	* memory & initialization
	*/
	m128a = _mm_set_ss(1.5f);										// r0 = w, r1 = r2 = r3 = 0.0
	m128b = _mm_set_ps1(1.5f);										// r0 = r1 = r2 = r3 = w
	m128a = _mm_set_ps(1.5f, 2.5f, 3.5f, 4.5f);						// r0 = w, r1 = x, r2 = y, r3 = z
	m128a = _mm_setr_ps(1.5f, 2.5f, 3.5f, 4.5f);					// r0 = z, r1 = y, r2 = x, r3 = w
	m128a = _mm_setzero_ps();										// r0 = r1 = r2 = r3 = 0.0
	m128a = _mm_load_ss(&cf);										// r0 = *p, r1 = 0.0; r2= 0.0; r3= 0.0
	m128a = _mm_load_ps1(&cf);										// r0 = *p, r1 = *p, r2 = *p, r3 = *p
	m128a = _mm_load_ps(&cf);										// r0 = p[0], r1 = p[1], r2 = p[2], r3 = p[3]
	m128a = _mm_loadr_ps(&cf);										// r0 = p[3], r1 = p[2], r2 = p[1], r3 = p[0]
	m128a = _mm_loadu_ps(&cf);										// r0 = p[0], r1 = p[1], r2 = p[2], r3 = p[3]
	_mm_store_ss(arrFloat4, m128a);									// *p = a0
	_mm_store_ps1(arrFloat4, m128a);								// p[0] = a0 p[1] = a0, p[2] = a0, p[3] = a0
	_mm_store_ps(arrFloat4, m128a);									// p[0] = a0 p[1] = a1, p[2] = a2, p[3] = a3
	_mm_storer_ps(arrFloat4, m128a);								// p[0] = a3 p[1] = a2, p[2] = a1, p[3] = a0
	_mm_storeu_ps(arrFloat4, m128a);								// p[0] = a0 p[1] = a1, p[2] = a2, p[3] = a3
	_mm_prefetch(&cc, _MM_HINT_T0);
	_mm_stream_ps(arrFloat4, m128a);								// p[0] = a0 p[1] = a1, p[2] = a2, p[3] = a3
	m128a = _mm_move_ss(m128a, m128b);                              // r0 = b0, r1 = a1, r2 = a2, r3 = a3
	_mm_sfence();
	ui = _mm_getcsr();
	_mm_setcsr(ui);

	/*
	* arithmetic
	*/
	m128a = _mm_add_ss(m128a, m128b);                               // r0 = a0 + b0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_add_ps(m128a, m128b);                               // r0 = a0 + b0, r1 = a1 + b1, r2 = a2 + b2, r3 = a3 + b3
	m128a = _mm_sub_ss(m128a, m128b);                               // r0 = a0 - b0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_sub_ps(m128a, m128b);                               // r0 = a0 - b0, r1 = a1 - b1, r2 = a2 - b2, r3 = a3 - b3
	m128a = _mm_mul_ss(m128a, m128b);                               // r0 = a0 * b0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_mul_ps(m128a, m128b);                               // r0 = a0 * b0, r1 = a1 * b1, r2 = a2 * b2, r3 = a3 * b3
	m128a = _mm_div_ss(m128a, m128b);                               // r0 = a0 / b0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_div_ps(m128a, m128b);                               // r0 = a0 / b0, r1 = a1 / b1, r2 = a2 / b2, r3 = a3 / b3
	m128a = _mm_sqrt_ss(m128a);										// r0 = sqrt(a0), r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_sqrt_ps(m128a);									    // r0 = sqrt(a0), r1 = sqrt(a1), r2 = sqrt(a2), r3 = sqrt(a3)
	m128a = _mm_rcp_ss(m128a);									    // r0 = recip(a0), r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_rcp_ps(m128a);										// r0 = recip(a0), r1 = recip(a1), r2 = recip(a2), r3 = recip(a3)
	m128a = _mm_rsqrt_ss(m128a);								    // r0 = recip(sqrt(a0)), r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_rsqrt_ps(m128a);									// r0 = recip(sqrt(a0)), r1 = recip(sqrt(a1)), r2 = recip(sqrt(a2)), r3 = recip(sqrt(a3))
	m128a = _mm_min_ss(m128a, m128b);                               // r0 = min(a0, b0), r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_min_ps(m128a, m128b);                               // r0 = min(a0, b0), r1 =  min(a1, b1), r2 =  min(a2, b2), r3 =  min(a3, b3)
	m128a = _mm_max_ss(m128a, m128b);                               // r0 = max(a0, b0), r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_max_ps(m128a, m128b);                               // r0 = max(a0, b0), r1 =  max(a1, b1), r2 =  max(a2, b2), r3 =  max(a3, b3)

	/*
	* logical
	*/
	m128a = _mm_and_ps(m128a, m128b);                               // r0 = a0 & b0, r1 = a1 & b1, r2 = a2 & b2, r3 = a3 & b3
	m128a = _mm_andnot_ps(m128a, m128b);                            // r0 = ~a0 & b0, r1 = ~a1 & b1, r2 = ~a2 & b2, r3 = ~a3 & b3
	m128a = _mm_or_ps(m128a, m128b);                                // r0 = a0 | b0, r1 = a1 | b1, r2 = a2 | b2, r3 = a3 | b3
	m128a = _mm_xor_ps(m128a, m128b);                               // r0 = a0 ^ b0, r1 = a1 ^ b1, r2 = a2 ^ b2, r3 = a3 ^ b3

	/*
	* comparison
	*/
	m128a = _mm_cmpeq_ss(m128a, m128b);                             // r0 = (a0 == b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpeq_ps(m128a, m128b);                             // r0 = (a0 == b0) ? 0xffffffff : 0x0, r1 = (a1 == b1) ? 0xffffffff : 0x0, r2 = (a2 == b2) ? 0xffffffff : 0x0, r3 = (a3 == b3) ? 0xffffffff : 0x0
	m128a = _mm_cmplt_ss(m128a, m128b);                             // r0 = (a0 < b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmplt_ps(m128a, m128b);                             // r0 = (a0 < b0) ? 0xffffffff : 0x0, r1 = (a1 < b1) ? 0xffffffff : 0x0, r2 = (a2 < b2) ? 0xffffffff : 0x0, r3 = (a3 < b3) ? 0xffffffff : 0x0
	m128a = _mm_cmple_ss(m128a, m128b);                             // r0 = (a0 <= b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmple_ps(m128a, m128b);                             // r0 = (a0 <= b0) ? 0xffffffff : 0x0, r1 = (a1 <= b1) ? 0xffffffff : 0x0, r2 = (a2 <= b2) ? 0xffffffff : 0x0, r3 = (a3 <= b3) ? 0xffffffff : 0x0
	m128a = _mm_cmpgt_ss(m128a, m128b);                             // r0 = (a0 > b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpgt_ps(m128a, m128b);                             // r0 = (a0 > b0) ? 0xffffffff : 0x0, r1 = (a1 > b1) ? 0xffffffff : 0x0, r2 = (a2 > b2) ? 0xffffffff : 0x0, r3 = (a3 > b3) ? 0xffffffff : 0x0
	m128a = _mm_cmpge_ss(m128a, m128b);                             // r0 = (a0 >= b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpge_ps(m128a, m128b);                             // r0 = (a0 >= b0) ? 0xffffffff : 0x0, r1 = (a1 >= b1) ? 0xffffffff : 0x0, r2 = (a2 >= b2) ? 0xffffffff : 0x0, r3 = (a3 >= b3) ? 0xffffffff : 0x0
	m128a = _mm_cmpneq_ss(m128a, m128b);                            // r0 = (a0 != b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpneq_ps(m128a, m128b);                            // r0 = (a0 != b0) ? 0xffffffff : 0x0, r1 = (a1 != b1) ? 0xffffffff : 0x0, r2 = (a2 != b2) ? 0xffffffff : 0x0, r3 = (a3 != b3) ? 0xffffffff : 0x0
	m128a = _mm_cmpnlt_ss(m128a, m128b);							// r0 = !(a0 < b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpnlt_ps(m128a, m128b);							// r0 = !(a0 < b0) ? 0xffffffff : 0x0, r1 = !(a1 < b1) ? 0xffffffff : 0x0, r2 = !(a2 < b2) ? 0xffffffff : 0x0, r3 = !(a3 < b3) ? 0xffffffff : 0x0
	m128a = _mm_cmpnle_ss(m128a, m128b);							// r0 = !(a0 <= b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpnle_ps(m128a, m128b);							// r0 = !(a0 <= b0) ? 0xffffffff : 0x0, r1 = !(a1 <= b1) ? 0xffffffff : 0x0, r2 = !(a2 <= b2) ? 0xffffffff : 0x0, r3 = !(a3 <= b3) ? 0xffffffff : 0x0
	m128a = _mm_cmpngt_ss(m128a, m128b);							// r0 = !(a0 > b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpngt_ps(m128a, m128b);							// r0 = !(a0 > b0) ? 0xffffffff : 0x0, r1 = !(a1 > b1) ? 0xffffffff : 0x0, r2 = !(a2 > b2) ? 0xffffffff : 0x0, r3 = !(a3 > b3) ? 0xffffffff : 0x0
	m128a = _mm_cmpnge_ss(m128a, m128b);							// r0 = !(a0 >= b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpnge_ps(m128a, m128b);							// r0 = !(a0 >= b0) ? 0xffffffff : 0x0, r1 = !(a1 >= b1) ? 0xffffffff : 0x0, r2 = !(a2 >= b2) ? 0xffffffff : 0x0, r3 = !(a3 >= b3) ? 0xffffffff : 0x0
	m128a = _mm_cmpord_ss(m128a, m128b);							// r0 = (a0 ord? b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpord_ps(m128a, m128b);							// r0 = (a0 ord? b0) ? 0xffffffff : 0x0, r1 = (a1 ord? b1) ? 0xffffffff : 0x0, r2 = (a2 ord? b2) ? 0xffffffff : 0x0, r3 = (a3 ord? b3) ? 0xffffffff : 0x0
	m128a = _mm_cmpunord_ss(m128a, m128b);							// r0 = (a0 unord? b0) ? 0xffffffff : 0x0, r1 = a1, r2 = a2, r3 = a3
	m128a = _mm_cmpunord_ps(m128a, m128b);							// r0 = (a0 unord? b0) ? 0xffffffff : 0x0, r1 = (a1 unord? b1) ? 0xffffffff : 0x0, r2 = (a2 unord? b2) ? 0xffffffff : 0x0, r3 = (a3 unord? b3) ? 0xffffffff : 0x0
	in = _mm_comieq_ss(m128a, m128b);								// r0 = (a0 == b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_comilt_ss(m128a, m128b);								// r0 = (a0 < b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_comile_ss(m128a, m128b);								// r0 = (a0 <= b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_comigt_ss(m128a, m128b);								// r0 = (a0 > b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_comige_ss(m128a, m128b);								// r0 = (a0 >= b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_comineq_ss(m128a, m128b);								// r0 = (a0 != b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_ucomieq_ss(m128a, m128b);								// r0 = (a0 == b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_ucomilt_ss(m128a, m128b);								// r0 = (a0 < b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_ucomile_ss(m128a, m128b);								// r0 = (a0 <= b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_ucomigt_ss(m128a, m128b);								// r0 = (a0 > b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_ucomige_ss(m128a, m128b);								// r0 = (a0 >= b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3
	in = _mm_ucomineq_ss(m128a, m128b);								// r0 = (a0 != b0) ? 0x1 : 0x0, r1 = a1, r2 = a2, r3 = a3

	/*
	* conversions
	*/
	in = _mm_cvt_ss2si(m128a);										// r = (int)a0
	in = _mm_cvtt_ss2si(m128a);										// r = (int)a0
    m128a = _mm_cvt_si2ss(m128a, in);								// r0 = (float)b, r1 = a1, r2 = a2, r3 = a3
	flo = _mm_cvtss_f32(m128a);										// r = a0

	/*
	* misc
	*/
	m128a = _mm_shuffle_ps(m128a, m128b, _MM_SHUFFLE(1, 2, 3, 4));  // r[0]=a[lo0], r[1] = a[lo1], r[2] = b[hi2], r[3] = b[hi3]
	m128a = _mm_unpackhi_ps(m128a, m128b);                          // r0 = a2, r1 = b2, r2 = a3, r3 = b3
	m128a = _mm_unpacklo_ps(m128a, m128b);                          // r0 = a0, r1 = b0, r2 = a1, r3 = b1
    m128a = _mm_loadh_pi(m128a, &m64);								// r0 = a0, r1 = a1, r2 = *p0, r3 = *p1
	m128a = _mm_movehl_ps(m128a, m128b);                            // r0 = b2, r1 = b3, r2 = a2, r3 = a3
	m128a = _mm_movelh_ps(m128a, m128b);                            // r0 = a0, r1 = a1, r2 = b0, r3 = b1
    _mm_storeh_pi(&m64, m128a);										// *p0 = a2, *p1 = a3
    m128a = _mm_loadl_pi(m128a, &m64);								// r0 = *p0, r1 = *p1, r2 = a2, r3 = a3
    _mm_storel_pi(&m64, m128a);										// *p0 := b0, *p1 : = b1
	in = _mm_movemask_ps(m128a);									// r = sign(a3)<<3 | sign(a2)<<2 | sign(a1)<<1 | sign(a0)

	/*
	* Alternate intrinsic names definition
	*/
	in = _mm_cvtss_si32(m128a);										// r = (int)a0
	in = _mm_cvttss_si32(m128a);									// r = (int)a0
	//m128a = _mm_cvtsi32_ss(m128a, in);								// r0 = (float)b, r1 = a1, r2 = a2, r3 = a3
	//m128a = _mm_set1_ps(1.5f);										// r0 = r1 = r2 = r3 = w
	//m128a = _mm_load1_ps(&cf);										// r0 = *p, r1 = *p, r2 = *p, r3 = *p
	_mm_store1_ps(arrFloat4, m128a);								// p[0] = a0 p[1] = a0, p[2] = a0, p[3] = a0

	// X64 only
#ifdef _M_X64
	/*
	* Support for 64-bit intrinsics
	*/
	i64 = _mm_cvtss_si64(m128a);									// r = (int)(a0+0.5)
	i64 = _mm_cvttss_si64(m128a);									// r = (int)a0
	m128a = _mm_cvtsi64_ss(m128a, i64);								// r0 = a0, r1 = a1, r2 = a2, r3 = b
#endif

	// X86 only
#ifdef _M_IX86
	/*
	* Support for MMX extension intrinsics
	*/
	m64 = _mm_cvt_ps2pi(m128a);
	m64 = _mm_cvtt_ps2pi(m128a);
	m128a = _mm_cvt_pi2ps(m128a, m64);

	/*
	* Integer (MMX) extensions
	*/
	in = _m_pextrw(m64, 0);											// r := (n==0) ? a0 : ( (n==1) ? a1 : ( (n==2) ? a2 : a3 ) )
	m64 = _m_pinsrw(m64, in, 0);									// r0 := (n==0) ? d : a0, r1: = (n == 1) ? d : a1, r2: = (n == 2) ? d : a2, r3: = (n == 3) ? d : a3;
	m64 = _m_pmaxsw(m64, m64);										// r0 = max(a0, b0), r1 =  max(a1, b1), r2 =  max(a2, b2), r3 =  max(a3, b3)
	m64 = _m_pmaxub(m64, m64);										// r0 = max(a0, b0), r1 =  max(a1, b1), r2 =  max(a2, b2), ..., r7 =  max(a7, b7)
	m64 = _m_pminsw(m64, m64);										// r0 = min(a0, b0), r1 =  min(a1, b1), r2 =  min(a2, b2), r3 =  min(a3, b3)
	m64 = _m_pminub(m64, m64);										// r0 = min(a0, b0), r1 =  min(a1, b1), r2 =  min(a2, b2), ..., r7 =  min(a7, b7)
	in = _m_pmovmskb(m64);											// r := sign(a7)<<7 | sign(a6)<<6 |... | sign(a0)
	m64 = _m_pmulhuw(m64, m64);										// r0 := hiword(a0 * b0), r1: = hiword(a1 * b1), r2 : = hiword(a2 * b2), r3 : = hiword(a3 * b3)
	m64 = _m_pshufw(m64, 0);										// r0 := word (n&0x3) of a, r1: = word((n >> 2) & 0x3) of a, r2 : = word((n >> 4) & 0x3) of a, r3 : = word((n >> 6) & 0x3) of a
	_m_maskmovq(m64, m64, arrChar4);								// if (sign(n0)) p[0] := d0 , if (sign(n1)) p[1] : = d1, ..., , if (sign(n7)) p[7] : = d7
	m64 = _m_pavgb(m64, m64);										// t = (unsigned short)a0 + (unsigned short)b0, r0 = (t >> 1) | (t & 0x01), ..., t = (unsigned short)a7 + (unsigned short)b7, r7 = (unsigned char)((t >> 1) | (t & 0x01))
	m64 = _m_pavgw(m64, m64);										// t = (unsigned int)a0 + (unsigned int)b0, r0 = (t >> 1) | (t & 0x01), ..., t = (unsigned word)a7 + (unsigned word)b7, r7 = (unsigned short)((t >> 1) | (t & 0x01))
	m64 = _m_psadbw(m64, m64);										// r0 = abs(a0 - b0) + ... + abs(a7 - b7), r1 = r2 = r3 = 0

	/*
	* memory & initialization
	*/
	_mm_stream_pi(&m64, m64);

	/*
	* Alternate intrinsic names definition
	*/
	m64 = _mm_cvtps_pi32(m128a);
	m64 = _mm_cvttps_pi32(m128a);
	m128a = _mm_cvtpi32_ps(m128a, m64);
	in = _mm_extract_pi16(m64, 0);									// r := (n==0) ? a0 : ( (n==1) ? a1 : ( (n==2) ? a2 : a3 ) )
	m64 = _mm_insert_pi16(m64, in, 0);								// r0 := (n==0) ? d : a0, r1: = (n == 1) ? d : a1, r2: = (n == 2) ? d : a2, r3: = (n == 3) ? d : a3;
	m64 = _mm_max_pi16(m64, m64);									// r0 = max(a0, b0), r1 =  max(a1, b1), r2 =  max(a2, b2), r3 =  max(a3, b3)
	m64 = _mm_max_pu8(m64, m64);									// r0 = max(a0, b0), r1 =  max(a1, b1), r2 =  max(a2, b2), ..., r7 =  max(a7, b7)
	m64 = _mm_min_pi16(m64, m64);									// r0 = min(a0, b0), r1 =  min(a1, b1), r2 =  min(a2, b2), r3 =  min(a3, b3)
	m64 = _mm_min_pu8(m64, m64);									// r0 = min(a0, b0), r1 =  min(a1, b1), r2 =  min(a2, b2), ..., r7 =  min(a7, b7)
	in = _mm_movemask_pi8(m64);										// r := sign(a7)<<7 | sign(a6)<<6 |... | sign(a0)
	m64 = _mm_mulhi_pu16(m64, m64);									// r0 := hiword(a0 * b0), r1: = hiword(a1 * b1), r2 : = hiword(a2 * b2), r3 : = hiword(a3 * b3)
	m64 = _mm_shuffle_pi16(m64, 0);									// r0 := word (n&0x3) of a, r1: = word((n >> 2) & 0x3) of a, r2 : = word((n >> 4) & 0x3) of a, r3 : = word((n >> 6) & 0x3) of a
	_mm_maskmove_si64(m64, m64, arrChar4);							// if (sign(n0)) p[0] := d0 , if (sign(n1)) p[1] : = d1, ..., , if (sign(n7)) p[7] : = d7
	m64 = _mm_avg_pu8(m64, m64);									// t = (unsigned short)a0 + (unsigned short)b0, r0 = (t >> 1) | (t & 0x01), ..., t = (unsigned short)a7 + (unsigned short)b7, r7 = (unsigned char)((t >> 1) | (t & 0x01))
	m64 = _mm_avg_pu16(m64, m64);									// t = (unsigned int)a0 + (unsigned int)b0, r0 = (t >> 1) | (t & 0x01), ..., t = (unsigned word)a7 + (unsigned word)b7, r7 = (unsigned short)((t >> 1) | (t & 0x01))
	m64 = _mm_sad_pu8(m64, m64);									// r0 = abs(a0 - b0) + ... + abs(a7 - b7), r1 = r2 = r3 = 0

	/*
	* Utility intrinsics function
	*/
	m128a = _mm_cvtpi16_ps(m64);
	m128a = _mm_cvtpu16_ps(m64);
	m64 = _mm_cvtps_pi16(m128a);
	m128a = _mm_cvtpi8_ps(m64);
	m128a = _mm_cvtpu8_ps(m64);
	m64 = _mm_cvtps_pi8(m128a);
	m128a = _mm_cvtpi32x2_ps(m64, m64);
#endif
}

