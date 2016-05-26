// This file is part of UDPipe <http://github.com/ufal/udpipe/>.
//
// Copyright 2016 Institute of Formal and Applied Linguistics, Faculty of
// Mathematics and Physics, Charles University in Prague, Czech Republic.
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <utility>

#include "common.h"
#include "model.h"

namespace ufal {
namespace udpipe {

class evaluator {
 public:
  evaluator(const model* m, const string& tokenizer, const string& tagger, const string& parser);

  void set_model(const model* m);
  void set_tokenizer(const string& tokenizer);
  void set_tagger(const string& tagger);
  void set_parser(const string& parser);

  bool evaluate(istream& is, ostream& os, string& error) const;

  static const string DEFAULT;
  static const string NONE;

 private:
  const model* m;
  string tokenizer, tagger, parser;

  struct f1_info { size_t total_system, total_gold; double precision, recall, f1; };
  template <class T>
  static f1_info evaluate_f1(const vector<pair<size_t, T>>& system, const vector<pair<size_t, T>>& gold);

  static const string space_after_no;
};

} // namespace udpipe
} // namespace ufal