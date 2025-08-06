.PHONY: clean synth

clean:
	@echo "🧹 Cleaning simulation build directories and temporary files..."
	@find ./tb -type d -name "__pycache__" -exec rm -rf {} +
	@find ./tb -type d -name "sim_build" -exec rm -rf {} +
	@find ./tb -type f -name "results.xml" -exec rm -f {} +
	@find ./tb -type f -name "*.None" -exec rm -f {} +
	@find ./tb -type d -name ".pytest_cache" -exec rm -rf {} +
	@find ./tb -type f -name "dump.vcd" -exec rm -f {} +

	@echo "🧹 Cleaning synthesis artifacts..."
	@rm -f ./cpu_synth.v
	@rm -f ./cpu_gates.v
	@rm -f ./cpu.json

	@echo "✅ Done. Workspace is clean!"

synth:
	@echo "🔧 Starting Yosys synthesis..."
	yosys synth.ys
	@echo "✅ Synthesis complete."
