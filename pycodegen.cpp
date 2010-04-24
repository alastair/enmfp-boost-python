#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include <boost/python/return_internal_reference.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>
#include "Codegen.h"

using namespace boost::python;

class pycodegen {
	public:
		pycodegen(list samples, int offset) {
			std::size_t n = len(samples);
			float* tmp = new float[n];
			for (int i = 0; i < n; i++) {
				tmp[i] = extract<float>(samples[i]);
			}

			_codegen = new Codegen(tmp, (uint)n, offset);
		}

		list getCodes() {
			uint numCodes = _codegen->getNumCodes();
			long *codes = _codegen->getCodes();
			list ret;
			for (uint i = 0; i < numCodes; i++) {
				ret.append(codes[i]);
			}
			return ret;
		}

		int getVersion() {
			return _codegen->getVersion();
		}

	private:
		Codegen* _codegen;
};

BOOST_PYTHON_MODULE(pycodegen) {
	class_<pycodegen>("pycodegen", init<list, int>())
		.def("getVersion", &pycodegen::getVersion)
		.def("getCodes", &pycodegen::getCodes)
	;
}
