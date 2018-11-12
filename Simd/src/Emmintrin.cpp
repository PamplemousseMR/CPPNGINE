#include "Simd.hpp"

#include <emmintrin.h>

/*  emmintrin
SSE2
Introduces instruction to work with 2 double precision floating point operands, and with packed byte/word/dword/qword integers in 128-bit xmm registers.
*/
void emmintrin()
{
    alignas(16) double arrDouble2[2] = {2.0, 3.0};
    __m128d m128da, m128db;
    __m128i m128ia, m128di;
    __m64 m64;
    const char cc = 'a';
    double doua = 10.5;
    double doub = 11.5;https://stackoverflow.com/questions/12399422/how-to-set-linker-flags-for-openmp-in-cmakes-try-compile-function
    int in = 10;
    long lo = 14;

    /*
    * memory & initialization
    */
    m128da = _mm_set_sd(doua);                                      // r0 = w, r1 = 0.0
    m128da = _mm_set1_pd(doua);                                     // r0 = r1 = w
    //m128da = _mm_set_pd1(doua);                                     // r0 = r1 = w
    //m128da = _mm_undefined_pd();                                    // r0 = r1 = ?
    m128da = _mm_setzero_pd();                                      // r0 = r1 = 0
    m128da = _mm_set_pd(doua, doub);                                // r0 = y, r1 = x
    m128db = _mm_setr_pd(doua, doub);                               // r0 = x, r1 = y
    m128da = _mm_move_sd(m128da, m128db);                           // r0 = &a0, r1 = b1
    m128da = _mm_load_pd(arrDouble2);                               // r0 = p[0], r1 = p[1]
    m128da = _mm_loadu_pd(arrDouble2);                              // r0 = p[0], r1 = p[1]
    m128da = _mm_load1_pd(arrDouble2);                              // r0 = p[0], r1 = p[0]
    m128da = _mm_load_sd(arrDouble2);                               // r0 = p[0], r1 = 0
    m128da = _mm_load_pd1(arrDouble2);                              // r0 = p[0], r1 = P[0]
    m128da = _mm_loadr_pd(arrDouble2);                              // r0 = p[1], r1 = P[0]
    _mm_store_pd(arrDouble2, m128da);                               // p[0] = a0, p[1] = a1
    _mm_storeu_pd(arrDouble2, m128da);                              // p[0] = a0, p[1] = a1
    _mm_store_sd(arrDouble2, m128da);                               // p[0] = a0, p[1] = a1
    doub = _mm_cvtsd_f64(m128da);                                   // p[0] = a0, p[1] = a1
    _mm_storel_pd(arrDouble2, m128da);                              // p[0] = a0, p[1] = a1
    _mm_storeh_pd(arrDouble2, m128da);                              // p[0] = a1, p[1] = a1
    _mm_store1_pd(arrDouble2, m128da);                              // p[0] = a0, p[1] = a0
    //_mm_store_pd1(arrDouble2, m128da);                              // p[0] = a0, p[1] = a0
    _mm_storer_pd(arrDouble2, m128da);                              // p[0] = a1, p[1] = a0

    /*
    * conversions
    */
    in = _mm_cvtsi128_si32(m128ia);
    lo = _mm_cvtsi128_si64(m128ia);
    //lo = _mm_cvtsi128_si64x(m128ia);

    /*
    * arithmetic
    */
    m128da = _mm_add_pd(m128da, m128db);                            // r0 = a0+b0, r1 = a1+b1
    m128da = _mm_add_sd(m128da, m128db);                            // r0 = a0+b0, r1 = a1
    m128da = _mm_sub_pd(m128da, m128db);                            // r0 = a0-b0, r1 = a1-b1
    m128da = _mm_sub_sd(m128da, m128db);                            // r0 = a0-b0, r1 = a1
    m128da = _mm_mul_pd(m128da, m128db);                            // r0 = a0*b0, r1 = a1*b1
    m128da = _mm_mul_sd(m128da, m128db);                            // r0 = a0*b0, r1 = a1
    m128da = _mm_div_pd(m128da, m128db);                            // r0 = a0/b0, r1 = a1/b1
    m128da = _mm_div_sd(m128da, m128db);                            // r0 = a0/b0, r1 = a1
    m128da = _mm_sqrt_pd(m128da);                                   // r0 = sqrt(a0), r1 = sqrt(a1)
    m128da = _mm_sqrt_sd(m128da, m128db);                           // r0 = sqrt(b0), r1 = a1
    m128da = _mm_min_pd(m128da, m128db);                            // r0 = min(a0,b0), r1 = min(a1,b1)
    m128da = _mm_min_sd(m128da, m128db);                            // r0 = min(a0,b0), r1 = a1
    m128da = _mm_max_pd(m128da, m128db);                            // r0 = max(a0,b0), r1 = max(a1,b1)
    m128da = _mm_max_sd(m128da, m128db);                            // r0 = max(a0,b0), r1 = a1

    /*
    * logical
    */
    m128da = _mm_and_pd(m128da, m128db);                            // r0 = a0 & b0, r1 = a1 & b1
    m128da = _mm_andnot_pd(m128da, m128db);                         // r0 = ~a0 & b0, r1 = ~a1 & b1,
    m128da = _mm_or_pd(m128da, m128db);                             // r0 = a0 | b0, r1 = a1 | b1
    m128da = _mm_xor_pd(m128da, m128db);                            // r0 = a0 ^ b0, r1 = a1 ^ b1

    /*
    * comparison
    */
    m128da = _mm_cmpeq_pd(m128da, m128db);                          // r0 = (a0 == b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmplt_pd(m128da, m128db);                          // r0 = (a0 == b0) ? 0xffffffff : 0x0, r1 = (a1 == b1) ? 0xffffffff : 0x0
    m128da = _mm_cmple_pd(m128da, m128db);                          // r0 = (a0 < b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpgt_pd(m128da, m128db);                          // r0 = (a0 < b0) ? 0xffffffff : 0x0, r1 = (a1 < b1) ? 0xffffffff : 0x0
    m128da = _mm_cmpge_pd(m128da, m128db);                          // r0 = (a0 <= b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpneq_pd(m128da, m128db);                         // r0 = (a0 <= b0) ? 0xffffffff : 0x0, r1 = (a1 <= b1) ? 0xffffffff : 0x0
    m128da = _mm_cmpnlt_pd(m128da, m128db);                         // r0 = (a0 > b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpnle_pd(m128da, m128db);                         // r0 = (a0 > b0) ? 0xffffffff : 0x0, r1 = (a1 > b1) ? 0xffffffff : 0x0
    m128da = _mm_cmpngt_pd(m128da, m128db);                         // r0 = (a0 >= b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpnge_pd(m128da, m128db);                         // r0 = (a0 >= b0) ? 0xffffffff : 0x0, r1 = (a1 >= b1) ? 0xffffffff : 0x0
    m128da = _mm_cmpord_pd(m128da, m128db);                         // r0 = (a0 );!= b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpunord_pd(m128da, m128db);                       // r0 = (a0 != b0) ? 0xffffffff : 0x0, r1 = (a1 != b1) ? 0xffffffff : 0x0
    m128da = _mm_cmpeq_sd(m128da, m128db);                          // r0 = !(a0 < b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmplt_sd(m128da, m128db);                          // r0 = !(a0 < b0) ? 0xffffffff : 0x0, r1 = !(a1 < b1) ? 0xffffffff : 0x0
    m128da = _mm_cmple_sd(m128da, m128db);                          // r0 = !(a0 <= b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpgt_sd(m128da, m128db);                          // r0 = !(a0 <= b0) ? 0xffffffff : 0x0, r1 = !(a1 <= b1) ? 0xffffffff : 0x0
    m128da = _mm_cmpge_sd(m128da, m128db);                          // r0 = !(a0 > b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpneq_sd(m128da, m128db);                         // r0 = !(a0 > b0) ? 0xffffffff : 0x0, r1 = !(a1 > b1) ? 0xffffffff : 0x0
    m128da = _mm_cmpnlt_sd(m128da, m128db);                         // r0 = !(a0 >= b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpnle_sd(m128da, m128db);                         // r0 = !(a0 >= b0) ? 0xffffffff : 0x0, r1 = !(a1 >= b1) ? 0xffffffff : 0x0
    m128da = _mm_cmpngt_sd(m128da, m128db);                         // r0 = (a0 ord? b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpnge_sd(m128da, m128db);                         // r0 = (a0 ord? b0) ? 0xffffffff : 0x0, r1 = (a1 ord? b1) ? 0xffffffff : 0x0
    m128da = _mm_cmpord_sd(m128da, m128db);                         // r0 = (a0 unord? b0) ? 0xffffffff : 0x0, r1 = a1
    m128da = _mm_cmpunord_sd(m128da, m128db);                       // r0 = (a0 unord? b0) ? 0xffffffff : 0x0, r1 = (a1 unord? b1) ? 0xffffffff : 0x0
    in = _mm_comieq_sd(m128da, m128db);                             // r = (a0 == b0) ? 0x1 : 0x0
    in = _mm_comilt_sd(m128da, m128db);                             // r = (a0 < b0) ? 0x1 : 0x0
    in = _mm_comile_sd(m128da, m128db);                             // r = (a0 <= b0) ? 0x1 : 0x0
    in = _mm_comigt_sd(m128da, m128db);                             // r = (a0 > b0) ? 0x1 : 0x0
    in = _mm_comige_sd(m128da, m128db);                             // r = (a0 >= b0) ? 0x1 : 0x0
    in = _mm_comineq_sd(m128da, m128db);                            // r = (a0 != b0) ? 0x1 : 0x0
    in = _mm_ucomieq_sd(m128da, m128db);                            // r = (a0 == b0) ? 0x1 : 0x0
    in = _mm_ucomilt_sd(m128da, m128db);                            // r = (a0 < b0) ? 0x1 : 0x0
    in = _mm_ucomile_sd(m128da, m128db);                            // r = (a0 <= b0) ? 0x1 : 0x0
    in = _mm_ucomigt_sd(m128da, m128db);                            // r = (a0 > b0) ? 0x1 : 0x0
    in = _mm_ucomige_sd(m128da, m128db);                            // r = (a0 >= b0) ? 0x1 : 0x0
    in = _mm_ucomineq_sd(m128da, m128db);                           // r = (a0 != b0) ? 0x1 : 0x0

/*
    __m128i _mm_set_epi64x (long long __q1, long long __q0)
    __m128i _mm_set_epi64 (__m64 __q1,  __m64 __q0)
    __m128i _mm_set_epi32 (int __q3, int __q2, int __q1, int __q0)
    __m128i _mm_set_epi16 (short __q7, short __q6, short __q5, short __q4, short __q3, short __q2, short __q1, short __q0)
    __m128i _mm_set_epi8 (char __q15, char __q14, char __q13, char __q12, char __q11, char __q10, char __q09, char __q08, char __q07, char __q06, char __q05, char __q04, char __q03, char __q02, char __q01, char __q00)
    __m128i _mm_set1_epi64x (long long __A)
    __m128i _mm_set1_epi64 (__m64 __A)
    __m128i _mm_set1_epi32 (int __A)
    __m128i _mm_set1_epi16 (short __A)
    __m128i _mm_set1_epi8 (char __A)
    __m128i _mm_setr_epi64 (__m64 __q0, __m64 __q1)
    __m128i _mm_setr_epi32 (int __q0, int __q1, int __q2, int __q3)
    __m128i _mm_setr_epi16 (short __q0, short __q1, short __q2, short __q3, short __q4, short __q5, short __q6, short __q7)
    __m128i _mm_setr_epi8 (char __q00, char __q01, char __q02, char __q03, char __q04, char __q05, char __q06, char __q07, char __q08, char __q09, char __q10, char __q11, char __q12, char __q13, char __q14, char __q15)
    __m128i _mm_load_si128 (__m128i const *__P)
    __m128i _mm_loadu_si128 (__m128i_u const *__P)
    __m128i _mm_loadl_epi64 (__m128i_u const *__P)
    void _mm_store_si128 (__m128i *__P, __m128i __B)
    void _mm_storeu_si128 (__m128i_u *__P, __m128i __B)
    void _mm_storel_epi64 (__m128i_u *__P, __m128i __B)
    __m64 _mm_movepi64_pi64 (__m128i __B)
    __m128i _mm_movpi64_epi64 (__m64 __A)
    __m128i _mm_move_epi64 (__m128i __A)
    __m128i _mm_undefined_si128 (void)
    __m128i _mm_setzero_si128 (void)
    __m128d _mm_cvtepi32_pd (__m128i __A)
    __m128 _mm_cvtepi32_ps (__m128i __A)
    __m128i _mm_cvtpd_epi32 (__m128d __A)
    __m64 _mm_cvtpd_pi32 (__m128d __A)
    __m128 _mm_cvtpd_ps (__m128d __A)
    __m128i _mm_cvttpd_epi32 (__m128d __A)
    __m64 _mm_cvttpd_pi32 (__m128d __A)
    __m128d _mm_cvtpi32_pd (__m64 __A)
    __m128i _mm_cvtps_epi32 (__m128 __A)
    __m128i _mm_cvttps_epi32 (__m128 __A)
    __m128d _mm_cvtps_pd (__m128 __A)
    int _mm_cvtsd_si32 (__m128d __A)
    long _mm_cvtsd_si64 (__m128d __A)
    long _mm_cvtsd_si64xblas tuto c++ (__m128d __A)
    int _mm_cvttsd_si32 (__m128d __A)
    long _mm_cvttsd_si64 (__m128d __A)
    long _mm_cvttsd_si64x (__m128d __A)
    __m128 _mm_cvtsd_ss (__m128 __A, __m128d __B)
    __m128d _mm_cvtsi32_sd (__m128d __A, int __B)
    __m128d _mm_cvtsi64_sd (__m128d __A, long long __B)
    __m128d _mm_cvtsi64x_sd (__m128d __A, long long __B)
    __m128d _mm_cvtss_sd (__m128d __A, __m128 __B)
    __m128d _mm_shuffle_pd(__m128d __A, __m128d __B, const int __mask)
    __m128d _mm_unpackhi_pd (__m128d __A, __m128d __B)
    __m128d _mm_unpacklo_pd (__m128d __A, __m128d __B)
    __m128d _mm_loadh_pd (__m128d __A, double const *__B)
    __m128d _mm_loadl_pd (__m128d __A, double const *__B)
    int _mm_movemask_pd (__m128d __A)
    __m128i _mm_packs_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_packs_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_packus_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_unpackhi_epi8 (__m128i __A, __m128i __B)
    __m128i _mm_unpackhi_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_unpackhi_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_unpackhi_epi64 (__m128i __A, __m128i __B)
    __m128i _mm_unpacklo_epi8 (__m128i __A, __m128i __B)
    __m128i _mm_unpacklo_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_unpacklo_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_unpacklo_epi64 (__m128i __A, __m128i __B)
    __m128i _mm_add_epi8 (__m128i __A, __m128i __B)
    __m128i _mm_add_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_add_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_add_epi64 (__m128i __A, __m128i __B)
    __m128i _mm_adds_epi8 (__m128i __A, __m128i __B)
    __m128i _mm_adds_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_adds_epu8 (__m128i __A, __m128i __B)
    __m128i _mm_adds_epu16 (__m128i __A, __m128i __B)
    __m128i _mm_sub_epi8 (__m128i __A, __m128i __B)
    __m128i _mm_sub_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_sub_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_sub_epi64 (__m128i __A, __m128i __B)
    __m128i _mm_subs_epi8 (__m128i __A, __m128i __B)
    __m128i _mm_subs_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_subs_epu8 (__m128i __A, __m128i __B)
    __m128i _mm_subs_epu16 (__m128i __A, __m128i __B)
    __m128i _mm_madd_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_mulhi_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_mullo_epi16 (__m128i __A, __m128i __B)
    __m64 _mm_mul_su32 (__m64 __A, __m64 __B)
    __m128i _mm_mul_epu32 (__m128i __A, __m128i __B)
    __m128i _mm_slli_epi16 (__m128i __A, int __B)
    __m128i _mm_slli_epi32 (__m128i __A, int __B)
    __m128i _mm_slli_epi64 (__m128i __A, int __B)
    __m128i _mm_srai_epi16 (__m128i __A, int __B)
    __m128i _mm_srai_epi32 (__m128i __A, int __B)
    __m128i _mm_bsrli_si128 (__m128i __A, const int __N)
    __m128i _mm_bslli_si128 (__m128i __A, const int __N)
    __m128i _mm_srli_si128 (__m128i __A, const int __N)
    __m128i _mm_slli_si128 (__m128i __A, const int __N)
    __m128i _mm_srli_epi16 (__m128i __A, int __B)
    __m128i _mm_srli_epi32 (__m128i __A, int __B)
    __m128i _mm_srli_epi64 (__m128i __A, int __B)
    __m128i _mm_sll_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_sll_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_sll_epi64 (__m128i __A, __m128i __B)
    __m128i _mm_sra_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_sra_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_srl_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_srl_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_srl_epi64 (__m128i __A, __m128i __B)
    __m128i _mm_and_si128 (__m128i __A, __m128i __B)
    __m128i _mm_andnot_si128 (__m128i __A, __m128i __B)
    __m128i _mm_or_si128 (__m128i __A, __m128i __B)
    __m128i _mm_xor_si128 (__m128i __A, __m128i __B)
    __m128i _mm_cmpeq_epi8 (__m128i __A, __m128i __B)
    __m128i _mm_cmpeq_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_cmpeq_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_cmplt_epi8 (__m128i __A, __m128i __B)
    __m128i _mm_cmplt_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_cmplt_epi32 (__m128i __A, __m128i __B)
    __m128i _mm_cmpgt_epi8 (__m128i __A, __m128i __B)
    __m128i _mm_cmpgt_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_cmpgt_epi32 (__m128i __A, __m128i __B)
    int _mm_extract_epi16 (__m128i const __A, int const __N)
    __m128i _mm_insert_epi16 (__m128i const __A, int const __D, int const __N)
    __m128i _mm_max_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_max_epu8 (__m128i __A, __m128i __B)
    __m128i _mm_min_epi16 (__m128i __A, __m128i __B)
    __m128i _mm_min_epu8 (__m128i __A, __m128i __B)
    int _mm_movemask_epi8 (__m128i __A)
    __m128i _mm_mulhi_epu16 (__m128i __A, __m128i __B)
    __m128i _mm_shufflehi_epi16 (__m128i __A, const int __mask)
    __m128i _mm_shufflelo_epi16 (__m128i __A, const int __mask)
    __m128i _mm_shuffle_epi32 (__m128i __A, const int __mask)
    void _mm_maskmoveu_si128 (__m128i __A, __m128i __B, char *__C)
    __m128i _mm_avg_epu8 (__m128i __A, __m128i __B)
    __m128i _mm_avg_epu16 (__m128i __A, __m128i __B)
    __m128i _mm_sad_epu8 (__m128i __A, __m128i __B)
    void _mm_stream_si32 (int *__A, int __B)
    void _mm_stream_si64 (long long int *__A, long long int __B)
    void _mm_stream_si128 (__m128i *__A, __m128i __B)
    void _mm_stream_pd (double *__A, __m128d __B)
    void _mm_clflush (void const *__A)
    void _mm_lfence (void)
    void _mm_mfence (void)
    __m128i _mm_cvtsi32_si128 (int __A)
    __m128i _mm_cvtsi64_si128 (long long __A)
    __m128i _mm_cvtsi64x_si128 (long long __A)
    __m128 _mm_castpd_ps(__m128d __A)
    __m128i _mm_castpd_si128(__m128d __A)
    __m128d _mm_castps_pd(__m128 __A)
    __m128i _mm_castps_si128(__m128 __A)
    __m128 _mm_castsi128_ps(__m128i __A)
    __m128d _mm_castsi128_pd(__m128i __A)
*/
}

