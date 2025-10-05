using System.IO;

[module: Sharpmake.Include("../atrium/engine/sharpmake.cs")]

[module: Sharpmake.Include("../atrium/extensions/DearImGui/sharpmake.cs")]

namespace Iris
{
	[Sharpmake.Generate]
	public class IrisExecutable : Atrium.ExecutableProject
	{
		public IrisExecutable()
		{
			Name = "Iris executable";
			SourceRootPath = "[project.SharpmakeCsPath]";
		}

		public override void ConfigureAll(Sharpmake.Project.Configuration conf, Sharpmake.Target target)
		{
			base.ConfigureAll(conf, target);

			conf.SolutionFolder = "Executables";
			
			conf.AddPrivateDependency<Atrium.Engine>(target);

			if (target.Optimization != Sharpmake.Optimization.Retail)
				conf.AddPrivateDependency<DearImGui>(target);

			// conf.VcxprojUserFile = new Sharpmake.Project.Configuration.VcxprojUserFileSettings();
			// conf.VcxprojUserFile.LocalDebuggerWorkingDirectory = "$(OutputPath)../data/";
		}
	}
}