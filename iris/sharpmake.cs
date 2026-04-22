using Sharpmake;

namespace Iris
{
	[Generate]
	public class IrisExecutable : Project
	{
		public IrisExecutable()
		{
			Name = "Iris executable";
			SourceRootPath = "[project.SharpmakeCsPath]";

			AddTargets(new Target(
				Platform.win64,
				Util.AllFlags<DevEnv>(),
				Util.AllFlags<Optimization>()
			));
		}

		[Configure]
		public void ConfigureAll(Configuration conf, Target target)
		{
			Util.SetDefaultBuildArguments(conf, target);
			conf.SolutionFolder = "Executables";
			
			conf.AddPrivateDependency<Atrium.Engine>(target);

			if (target.Optimization != Sharpmake.Optimization.Retail)
				conf.AddPrivateDependency<Atrium.Extension.DearImGui>(target);

			if (target.Platform == Platform.win32 || target.Platform == Platform.win64)
				conf.Options.Add(Sharpmake.Options.Vc.Linker.SubSystem.Windows);

			conf.Output = Configuration.OutputType.Exe;
		}
	}
}