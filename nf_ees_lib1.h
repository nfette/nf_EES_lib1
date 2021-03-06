#ifndef NF_EES_LIB1_H
#define NF_EES_LIB1_H

#include "nf_ees_lib1_global.h"
#include "ees_common.h"
#include <fstream>
#include "c_nfadd.h"
#include "c_nfpyadd.h"
#include "c_nftliq.h"
#include "c_nfsatmix.h"
#include "c_nfmixtherm.h"
#include "c_nfpcrit.h"
#include "c_nfp_libr.h"
#include "c_nft_libr.h"
#include "c_nfh_libr.h"
#include "c_nfv_libr.h"
#include "c_nfx_libr.h"
#include "c_nfq_libr.h"
#include <CoolProp.h>

class myLib {
  C_NFADD nfadder;
  c_nfpyadd nfpyadd;
  C_nftliq nftliquor;
  c_nfsatmix nfsatmix;
  c_nfmixtherm nfmixtherm;
  c_nfpcrit nfpcrit;
  c_nfp_libr nfp_libr;
  c_nft_libr nft_libr;
  c_nfh_libr nfh_libr;
  c_nfv_libr nfv_libr;
  c_nfx_libr nfx_libr;
  c_nfq_libr nfq_libr;

public:
  static void logtimestamp(std::ofstream &ofs);
  static std::ofstream & getofs();
  static void logPvalue(double P);
  myLib();
  ~myLib();
  EesDLF & getNfadd();
  EesDLF &getNfpyadd();
  EesDLP &getNftliq();
  EesDLP &getNfsatmix();
  EesDLP &getNftherm();
  EesDLF &getNfpcrit();
  EesDLF &getNfp_libr();
  EesDLF &getNft_libr();
  EesDLF &getNfh_libr();
  EesDLF &getNfv_libr();
  EesDLF &getNfx_libr();
  EesDLP &getNfq_libr();
};

myLib & getLib();

// Tell EES which functions and procedures are exported in the library :
// List of DLF format functions.
NF_EES_LIB1SHARED_EXPORT void NF_CALLCODE DLFNames(char* Names);
// List of DLP format procedures.
NF_EES_LIB1SHARED_EXPORT void NF_CALLCODE DLPNames(char *Names);
// List of FDL format procedures.
NF_EES_LIB1SHARED_EXPORT void NF_CALLCODE FDLNames(char* Names);

// EES DLFs (Functions)
// A very boring function.
NF_EES_LIB1SHARED_EXPORT double NF_CALLCODE NFADD(char s[256], int &mode,
  struct EesParamRec *input_rec);
NF_EES_LIB1SHARED_EXPORT double NF_CALLCODE NFPYADD(char s[256], int &mode,
  struct EesParamRec *input_rec);
NF_EES_LIB1SHARED_EXPORT double NF_CALLCODE NFPCRIT(char s[256], int &mode,
  struct EesParamRec *input_rec);
NF_EES_LIB1SHARED_EXPORT double NF_CALLCODE NFP_LIBR(char s[256], int &mode,
  struct EesParamRec *input_rec);
NF_EES_LIB1SHARED_EXPORT double NF_CALLCODE NFT_LIBR(char s[256], int &mode,
  struct EesParamRec *input_rec);
NF_EES_LIB1SHARED_EXPORT double NF_CALLCODE NFH_LIBR(char s[256], int &mode,
  struct EesParamRec *input_rec);
NF_EES_LIB1SHARED_EXPORT double NF_CALLCODE NFV_LIBR(char s[256], int &mode,
  struct EesParamRec *input_rec);
NF_EES_LIB1SHARED_EXPORT double NF_CALLCODE NFX_LIBR(char s[256], int &mode,
  struct EesParamRec *input_rec);

// A less boring function.
NF_EES_LIB1SHARED_EXPORT void NF_CALLCODE NFTLIQ(char s[256], int &mode,
  struct EesParamRec *input_rec, struct EesParamRec *output_rec);

NF_EES_LIB1SHARED_EXPORT void NF_CALLCODE NFSATMIX(char s[256], int &mode,
  struct EesParamRec *input_rec, struct EesParamRec *output_rec);

NF_EES_LIB1SHARED_EXPORT void NF_CALLCODE NFMIXTHERM(char s[256], int &mode,
  struct EesParamRec *input_rec, struct EesParamRec *output_rec);

NF_EES_LIB1SHARED_EXPORT void NF_CALLCODE NFQ_LIBR(char s[256], int &mode,
  struct EesParamRec *input_rec, struct EesParamRec *output_rec);

#endif // NF_EES_LIB1_H
