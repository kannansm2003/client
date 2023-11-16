/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2022 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/err.h>
#include <openssl/cryptoerr.h>
#include "crypto/cryptoerr.h"

#ifndef OPENSSL_NO_ERR

static const ERR_STRING_DATA CRYPTO_str_reasons[] = {
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_BAD_ALGORITHM_NAME),
    "bad algorithm name"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_CONFLICTING_NAMES),
    "conflicting names"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_HEX_STRING_TOO_SHORT),
    "hex string too short"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_ILLEGAL_HEX_DIGIT),
    "illegal hex digit"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_INSUFFICIENT_DATA_SPACE),
    "insufficient data space"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_INSUFFICIENT_PARAM_SIZE),
    "insufficient param size"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_INSUFFICIENT_SECURE_DATA_SPACE),
    "insufficient secure data space"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_INTEGER_OVERFLOW),
    "integer overflow"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_INVALID_NEGATIVE_VALUE),
    "invalid negative value"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_INVALID_NULL_ARGUMENT),
    "invalid null argument"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_INVALID_OSSL_PARAM_TYPE),
    "invalid ossl param type"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_NO_PARAMS_TO_MERGE),
    "no params to merge"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_NO_SPACE_FOR_TERMINATING_NULL),
    "no space for terminating null"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_ODD_NUMBER_OF_DIGITS),
    "odd number of digits"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_PARAM_CANNOT_BE_REPRESENTED_EXACTLY),
    "param cannot be represented exactly"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_PARAM_NOT_INTEGER_TYPE),
    "param not integer type"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_PARAM_OF_INCOMPATIBLE_TYPE),
    "param of incompatible type"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_PARAM_UNSIGNED_INTEGER_NEGATIVE_VALUE_UNSUPPORTED),
    "param unsigned integer negative value unsupported"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_PARAM_UNSUPPORTED_FLOATING_POINT_FORMAT),
    "param unsupported floating point format"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_PARAM_VALUE_TOO_LARGE_FOR_DESTINATION),
    "param value too large for destination"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_PROVIDER_ALREADY_EXISTS),
    "provider already exists"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_PROVIDER_SECTION_ERROR),
    "provider section error"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_RANDOM_SECTION_ERROR),
    "random section error"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_SECURE_MALLOC_FAILURE),
    "secure malloc failure"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_STRING_TOO_LONG), "string too long"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_TOO_MANY_BYTES), "too many bytes"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_TOO_MANY_RECORDS),
    "too many records"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_TOO_SMALL_BUFFER),
    "too small buffer"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_UNKNOWN_NAME_IN_RANDOM_SECTION),
    "unknown name in random section"},
    {ERR_PACK(ERR_LIB_CRYPTO, 0, CRYPTO_R_ZERO_LENGTH_NUMBER),
    "zero length number"},
    {0, NULL}
};

#endif

int ossl_err_load_CRYPTO_strings(void)
{
#ifndef OPENSSL_NO_ERR
    if (ERR_reason_error_string(CRYPTO_str_reasons[0].error) == NULL)
        ERR_load_strings_const(CRYPTO_str_reasons);
#endif
    return 1;
}
