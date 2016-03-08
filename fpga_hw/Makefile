

MODELS = models

COMMAND = "if {![does_tlm_library_exist $(MODELS)]} \
              {create_tlm_library $(MODELS) $(MODELS)}; \
           reload_tlm_library $(MODELS);\
           foreach n [glob -directory $(MODELS) -tails *.mb] { \
             save_model -g TLM/$(MODELS)/[lindex [split \$$n .] 0] }"

mb:
	if [ -e $(MODELS) ]; then vista_model_builder -c $(COMMAND); fi

