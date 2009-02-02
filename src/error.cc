/*
 * Copyright (c) 2003-2009, John Wiegley.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * - Neither the name of New Artisans LLC nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "utils.h"

namespace ledger {

std::ostringstream _desc_buffer;
std::ostringstream _ctxt_buffer;

string error_context()
{
  string context = _ctxt_buffer.str();
  _ctxt_buffer.str("");
  return context;
}

string file_context(const path& file, std::size_t line)
{
  std::ostringstream buf;
  buf << "\"" << file << "\", line " << line << ": ";
  return buf.str();
}

string line_context(const string&    line,
		    istream_pos_type pos,
		    istream_pos_type end_pos)
{
  std::ostringstream buf;
  buf << "  " << line << "\n";

  if (pos != istream_pos_type(0)) {
    buf << "  ";
    if (end_pos == istream_pos_type(0)) {
      for (istream_pos_type i = 0; i < pos; i += 1)
	buf << " ";
      buf << "^";
    } else {
      for (istream_pos_type i = 0; i < end_pos; i += 1) {
	if (i >= pos)
	  buf << "^";
	else
	  buf << " ";
      }
    }
  }
  return buf.str();
}

} // namespace ledger
